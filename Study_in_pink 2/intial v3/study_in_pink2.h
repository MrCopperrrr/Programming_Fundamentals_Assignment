/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_2_H_
#define _H_STUDY_IN_PINK_2_H_

#include "main.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Forward declaration


 
//class BaseBag;
    //class SherlockBag;
    //class WatsonBag;

class MapElement;
    class Path;
    class Wall;
    class FakeWall;
 
class Position;
class MovingObject;
    class Sherlock;
    class Watson;
    class Criminal;
class Character;
class Robot;
    class RobotC;
    class RobotS;
    class RobotW;
    class RobotSW;
class Map;

class ArrayMovingObject;
class Configuration;


class BaseItem;
    class MagicBook;
    class EnergyDrink;
    class FirstAid;
    class ExcemptionCard;


class StudyPinkProgram;

class TestStudyInPink;

enum ItemType { MAGIC_BOOK, ENERGY_DRINK, FIRST_AID, EXCEMPTION_CARD, PASSING_CARD };
enum ElementType { PATH, WALL, FAKE_WALL };
enum RobotType { C=0, S, W, SW };
enum MovingObjectType { SHERLOCK, WATSON, CRIMINAL, ROBOT };
    

//3.1
class MapElement {  
    friend class TestStudyInPink;
protected:
    ElementType type;
public:
    MapElement(ElementType in_type);
    virtual ~MapElement();
    virtual ElementType getType() const;
};

class Path : public MapElement {
    friend class TestStudyInPink;
    public:
    Path();
};

class Wall : public MapElement {
    friend class TestStudyInPink;
    public:
    Wall();
};

class FakeWall : public MapElement {
    friend class TestStudyInPink;
private:
    int req_exp;
public:
    FakeWall(int in_req_exp);
    int getReqExp() const;
    
};

//3.3
class Position {
    friend class TestStudyInPink;
private:
    int r, c;
public:
    static const Position npos;

    Position(int r=0, int c=0);
    Position(const string & str_pos);

    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);

    string str() const;

    bool isEqual(Position position) const;
    
    bool operator!=(const Position &other) const {
        return r != other.r || c != other.c;
    }
    bool operator==(const Position &other) const {
    return r == other.r && c == other.c;
    }
    int getX() const { return r; }
    int getY() const { return c; }
};



//3.4
class MovingObject {
    friend class TestStudyInPink;
protected:
    int index;
    Position pos;
    Map * map;
    string name;

public:
    MovingObject(int index, const Position pos, Map * map, const string & name="");
    virtual ~MovingObject();
    virtual MovingObjectType getObjectType() const = 0;         
    virtual Position getNextPosition() = 0;               
    Position getCurrentPosition() const;    
    virtual void move() = 0;        
    virtual string str() const = 0;
    string getName() const { return name; } 
    virtual int getEXP() const; 
};

//3.11
class Character {
    friend class TestStudyInPink;
public:
    Character(const string& name, int hp, int exp);
    virtual ~Character();
    virtual MovingObjectType getObjectType() const = 0;
    void setHP(int hp);
    int getHP() const;
    void setEXP(int exp);
    int getEXP() const;
    void setName(const string& name);
    string getName() const;
    virtual bool canUseItem(BaseItem* item, Robot* robot) = 0;
    virtual void useItem(BaseItem* item, Robot* robot) = 0;
    virtual void encounter(MovingObject* obj) = 0;

protected:
    string name;
    int hp;
    int exp;
};


//3.6
class Watson : public MovingObject {
    friend class TestStudyInPink;
private:
    string moving_rule;
    int hp;
    int exp;
    Position position; 
    

public:
    Watson(int index, const string &moving_rule, const Position &init_pos, Map *map, int init_hp, int init_exp);
    Position getNextPosition() override;
    MovingObjectType getObjectType() const;
    void move() override;
    string str() const override;
    int getHP() const; 
    int getEXP() const override; 
    string getName() const ; 
    Position getPosition() const; 
    void setPosition(const Position &pos); 

    void decreaseEXP(int amount) {
    exp -= amount;
    }
    
};


//3.5
class Sherlock : public MovingObject {
    friend class TestStudyInPink;
private:
    string moving_rule;
    int hp;
    int exp;
    Position position;  

public:
    Sherlock(int index, const string &moving_rule, const Position &init_pos, Map *map, int init_hp, int init_exp);
    Position getNextPosition() override;
    void move() override;
    MovingObjectType getObjectType() const;
    string str() const override;
    int getHP() const; 
    int getEXP() const override;
    string getName() const;  
    Position getPosition() const; 
    void setPosition(const Position &pos); 
    
    void decreaseEXP(int amount) {
        exp -= amount;
    }
    void decreaseHP(int amount) {
        hp -= amount;
    }
};




//3.7
class Criminal : public MovingObject {
    friend class TestStudyInPink;
private:
    Sherlock *sherlock;
    Watson *watson;
    bool caught; 
    int count1; 
    Position previous_pos; 
public:
    Criminal(int index, const Position &init_pos, Map *map, Sherlock *sherlock, Watson *watson);
    Position getNextPosition() override;
    Position getPreviousPosition() const;
    MovingObjectType getObjectType() const;
    void move() override;
    string str() const override;
    string getName() const; 
    void setCaught(bool isCaught) {
        caught = isCaught;
    }
    ~Criminal() override;
    int getCount() const;
    int getEXP() const override; 
};


//3.10
class Robot : public MovingObject
{
protected:
    Criminal *criminal;
    RobotType robot_type;
    Position position;

public:
    Robot(int index, const Position &pos, Map *map, RobotType robot_type, Criminal *criminal, const string &name = "");
    virtual ~Robot();
    MovingObjectType getObjectType() const;
    static Robot *create(int index, Map *map, Criminal *criminal, Sherlock *sherlock, Watson *watson);
    virtual Position getNextPosition() = 0;
    virtual void move() = 0;
    virtual string str() const = 0;
    virtual RobotType getType() const = 0;
    virtual int getDistance() const = 0;
    void setPosition(const Position& pos) {
        position = pos;
    }
    void testCriminal()
    {
        cout << criminal->str() << endl;
    }
    
};
class RobotC : public Robot{
public:
    RobotC(int index, const Position &init_pos, Map *map, Criminal *criminal);
    ~RobotC();
    int getDistance(Sherlock *sherlock);

    int getDistance(Watson *watson);
    Position getNextPosition() override;
    void move();
    string str() const override;
    int getDistance() const override;
    RobotType getType() const override;
};




class RobotW : public Robot
{
private:
    Watson *watson;

public:
    RobotW(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Watson *watson);
    ~RobotW();
    Position getNextPosition() override;
    void move() override;
    string str() const override;
    RobotType getType() const override;
    int getDistance() const override;
};

class RobotS : public Robot
{
private:
    Sherlock *sherlock;

public:
    RobotS(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Sherlock *sherlock);
    ~RobotS();
    Position
    getNextPosition() override;
    void move() override;
    string str() const override;
    RobotType getType() const override;
    int getDistance() const override;
};

class RobotSW : public Robot
{
private:
    Sherlock *sherlock;
    Watson *watson;

public:
    RobotSW(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Sherlock *sherlock, Watson *watson);
    ~RobotSW();
    Position getNextPosition() override;
    string str() const;
    RobotType getType() const override;
    int getDistance() const override;
    void move() override;
};


//3.2
class Map {
    friend class TestStudyInPink;
private:
    int num_rows, num_cols;
    MapElement ***map; 
public:
    Map(int num_rows, int num_cols, int num_walls =0, Position * array_walls =nullptr, int num_fake_walls =0, Position * array_fake_walls =nullptr); //: num_rows(num_rows), num_cols(num_cols);
    ~Map();
    bool isValid ( const Position & pos , class MovingObject * mv_obj ) const ;
    
};



//3.8
class ArrayMovingObject {
    friend class TestStudyInPink;
private:
    MovingObject **arr_mv_objs;
    int count;
    int capacity;

public:
    ArrayMovingObject(int capacity);
    ~ArrayMovingObject() ;
    bool isFull() const;
    bool add(MovingObject * mv_obj);
    MovingObject * get(int index) const;
    int size() const;
    string str() const;
};

//3.9
class Configuration {
    friend class TestStudyInPink;
    friend class StudyPinkProgram;

private:
    int map_num_rows, map_num_cols;
    int max_num_moving_objects;
    int num_walls;
    Position *arr_walls;
    int num_fake_walls;
    Position *arr_fake_walls;
    string sherlock_moving_rule;
    Position sherlock_init_pos;
    int sherlock_init_hp;
    int sherlock_init_exp;
    string watson_moving_rule;
    Position watson_init_pos;
    int watson_init_hp;
    int watson_init_exp;
    Position criminal_init_pos;
    int num_steps;

public:
    Configuration(const string & filepath);
    ~Configuration();
    string str() const;
};


//3.11
class BaseItem {
    friend class TestStudyInPink;
public:
    BaseItem();
    virtual ~BaseItem();
    virtual string getItemType() const = 0; 
    virtual bool canUse(Character* obj, Robot* robot) = 0;
    virtual void use(Character* obj, Robot* robot) = 0;
};

class MagicBook : public BaseItem {
    friend class TestStudyInPink;
public:
    string getItemType() const override { return "MagicBook"; } 
    bool canUse(Character* obj, Robot* robot) override;
    void use(Character* obj, Robot* robot) override;
};

class EnergyDrink : public BaseItem {
    friend class TestStudyInPink;
public:
    string getItemType() const override { return "EnergyDrink"; } 
    bool canUse(Character* obj, Robot* robot) override;
    void use(Character* obj, Robot* robot) override;
};

class FirstAid : public BaseItem {
    friend class TestStudyInPink;
public:
    string getItemType() const override { return "FirstAid"; } 
    bool canUse(Character* obj, Robot* robot) override;
    void use(Character* obj, Robot* robot) override;
};

class ExcemptionCard : public BaseItem {
    friend class TestStudyInPink;
public:
    string getItemType() const override { return "ExcemptionCard"; } 
    bool canUse(Character* obj, Robot* robot) override;
    void use(Character* obj, Robot* robot) override;
};

class PassingCard : public BaseItem {
    friend class TestStudyInPink;
private:
    string challenge;

public:
    PassingCard(int i, int j);
    string getItemType() const override { return "PassingCard"; } 
    bool canUse(Character* obj, Robot* robot) override;
    void use(Character* obj, Robot* robot) override;
}; 


//3.12
class BaseBag {};


//3.13
class StudyPinkProgram {
    friend class TestStudyInPink;
private:
    Configuration* config;
    Sherlock* sherlock;
    Watson* watson;
    Criminal* criminal;
    Map* map;
    ArrayMovingObject* arr_mv_objs;


public:
    StudyPinkProgram(const string & config_file_path);

    bool isStop() const;

    void printResult() const {
        if (sherlock->getCurrentPosition() == criminal->getCurrentPosition()) {
            cout << "Sherlock caught the criminal" << endl;
        }
        else if (watson->getCurrentPosition() == criminal->getCurrentPosition()) {
        cout << "Watson caught the criminal" << endl;
        }
        else {
            cout << "The criminal escaped" << endl;
        }
    }

    void printStep(int si) const {
        cout << "Step: " << setw(4) << setfill('0') << si
            << "--"
            << sherlock->str() << "--|--" << watson->str() << "--|--" << criminal->str() << endl;
    }

    void run(bool verbose);

    ~StudyPinkProgram();
};

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_2_H_ */
