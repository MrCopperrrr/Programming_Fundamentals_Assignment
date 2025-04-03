#include "study_in_pink2.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//3.1 3.2 3.3
// Implementation of MapElement

MapElement::MapElement(ElementType in_type) : type(in_type) {}  // Constructor của MapElement
MapElement::~MapElement() {}    // Destructor của MapElement

ElementType MapElement::getType() const {       // Hàm trả về kiểu của MapElement
    return type;
}

Path::Path() : MapElement(PATH) {}      // Constructor của Path
Wall::Wall() : MapElement(WALL) {}          // Constructor của Wall
FakeWall::FakeWall(int in_req_exp) : MapElement(FAKE_WALL), req_exp(in_req_exp) {} // Constructor của FakeWall

int FakeWall::getReqExp() const { // Hàm trả về exp yêu cầu để pass FakeWall
    int r = 0; 
    int c = 0; 
    int in_req_exp = (r * 257 + c * 139 + 89) % 900 + 1;
    in_req_exp = req_exp;
    return req_exp;
}


Position::Position(int r, int c) : r(r), c(c) {}    // Constructor của Position
Position::Position(const string &str_pos) { // Constructor của Position
    stringstream ss(str_pos);   // Tạo một stringstream từ str_pos
    char ch;    
    ss >> ch >> r >> ch >> c >> ch; // Đọc dữ liệu từ stringstream
}

int Position::getRow() const {  // Hàm trả về hàng của Position
    return r;
}

int Position::getCol() const {  // Hàm trả về cột của Position
    return c;
}

void Position::setRow(int r) {  // Hàm set hàng của Position
    this->r = r;
}

void Position::setCol(int c) {  // Hàm set cột của Position
    this->c = c;
}

string Position::str() const {  // Hàm trả về chuỗi biểu diễn của Position
    stringstream ss;
    ss << "(" << r << "," << c << ")";
    return ss.str();
}

bool Position::isEqual(Position position) const {   // Hàm kiểm tra xem 2 Position có bằng nhau ko
    if (position.r == this->r && position.c == this->c) return true;    // Nếu hàng và cột của 2 Position bằng nhau thì trả về true
    else return false;
}


Map::Map(int num_rows, int num_cols, int num_walls, Position *array_walls, int num_fake_walls, Position *array_fake_walls) : num_rows(num_rows), num_cols(num_cols) {   // Constructor của Map
    map = new MapElement**[num_rows];           // Tạo mảng 2 chiều map
    for (int i = 0; i < num_rows; ++i) {        // Duyệt qua hàng
        map[i] = new MapElement*[num_cols];     // Tạo mảng con của map
        for (int j = 0; j < num_cols; ++j) {    // Duyệt qua cột
            map[i][j] = new Path(); 
        }
    }

   
    for (int i = 0; i < num_walls; ++i) {       // Duyệt qua số lượng walls
        int row = array_walls[i].getRow();      // Lấy hàng của wall
        int col = array_walls[i].getCol();      // Lấy cột của wall
        delete map[row][col];                   // Xóa map[row][col]
        map[row][col] = new Wall();
    }

   
    for (int i = 0; i < num_fake_walls; ++i) {      // Duyệt qua số lượng fake walls
        int row = array_fake_walls[i].getRow();     // Lấy hàng của fake wall
        int col = array_fake_walls[i].getCol();     // Lấy cột của fake wall
        delete map[row][col];                       // Xóa map[row][col]
        int req_exp = (row * 257 + col * 139 + 89) % 900 + 1;   // Tính exp yêu cầu để pass fake wall
        map[row][col] = new FakeWall(req_exp);     // Tạo fake wall mới
    }
}

Map::~Map() {   // Destructor của Map
    for (int i = 0; i < num_rows; ++i) {        // Duyệt qua hàng
        for (int j = 0; j < num_cols; ++j) {    // Duyệt qua cột
            delete map[i][j];
        }
        delete[] map[i];
    }
    
}


//3.4
const Position Position::npos = Position(-1, -1);   // Khởi tạo Position::npos

MovingObject::MovingObject(int index, const Position pos, Map *map, const string &name)     // Constructor của MovingObject
    : index(index), pos(pos), map(map), name(name) {}

MovingObject::~MovingObject() {}    // Destructor của MovingObject

int MovingObject::getEXP() const {   // Hàm trả về exp của MovingObject
    return 0;
}


Position MovingObject::getCurrentPosition() const {  // Hàm trả về vị trí hiện tại của MovingObject
    return pos;
}
bool Map::isValid(const Position &pos, MovingObject *mv_obj) const {    // Hàm kiểm tra xem vị trí pos có hợp lệ không
        if (pos.getRow() < 0 || pos.getRow() >= num_rows || pos.getCol() < 0 || pos.getCol() >= num_cols) {   // Nếu vị trí pos nằm ngoài map thì trả về false
            return false;
        }

        MapElement *element = map[pos.getRow()][pos.getCol()];  // Lấy phần tử tại vị trí pos

        if (element == nullptr) {   // Nếu phần tử đó là nullptr thì trả về false
            return true; 
        }

        if (element->getType() == WALL) {   // Nếu phần tử đó là WALL thì trả về false
            return false; 
        }

        if (element->getType() == FAKE_WALL && mv_obj->getName() == "Watson") {  // Nếu phần tử đó là FAKE_WALL và MovingObject là Watson
            FakeWall *fake_wall = dynamic_cast<FakeWall *>(element);            // Ép kiểu element thành FakeWall
            if (fake_wall && mv_obj->getEXP() < fake_wall->getReqExp()) {       // Nếu exp của MovingObject nhỏ hơn exp yêu cầu để pass FakeWall thì trả về false
                return false; 
            }
        }
        return true;
    }


//3.6
// Constructor của Watson
Watson::Watson(int index, const string &moving_rule, const Position &init_pos, Map *map, int init_hp, int init_exp) 
    : MovingObject(index, init_pos, map, "Watson"), moving_rule(moving_rule), hp((init_hp < 0) ? 0 : (init_hp > 500) ? 500 : init_hp), exp((init_exp < 0) ? 0 : (init_exp > 900) ? 900 : init_exp){}    
    // Khởi tạo Watson
        

Position Watson::getPosition() const {  // Hàm trả về vị trí của Watson
    return pos;
}

int Watson::getHP() const {             // Hàm trả về HP của Watson
    return hp;
}

int Watson::getEXP() const {            // Hàm trả về EXP của Watson
    return exp;
}


Position Watson::getNextPosition() {    // Hàm trả về vị trí tiếp theo của Watson
    static size_t current_index = 0;    // Khởi tạo biến static current_index
    char direction = moving_rule[current_index];    // Lấy hướng di chuyển
    current_index = (current_index + 1) % moving_rule.length();   // Cập nhật current_index

    int new_row = pos.getRow();     // Lấy hàng mới
    int new_col = pos.getCol();     // Lấy cột mới

    switch (direction) {    // Xét hướng di chuyển
        case 'L':
            new_col--;
            break;
        case 'R':
            new_col++;
            break;
        case 'U':
            new_row--;
            break;
        case 'D':
            new_row++;
            break;
    }

    Position next_pos(new_row, new_col);    // Tạo vị trí mới
    return (map->isValid(next_pos, this)) ? next_pos : Position::npos;  // Nếu vị trí mới hợp lệ thì trả về vị trí mới, ngược lại trả về Position::npos
}

void Watson::move() {   // Hàm di chuyển của Watson
    Position next_pos = getNextPosition();  // Lấy vị trí tiếp theo
    if (!next_pos.isEqual(Position::npos)) {    // Nếu vị trí tiếp theo không phải Position::npos
        this->pos = next_pos;   
    }
}

string Watson::str() const {    // Hàm trả về chuỗi biểu diễn của Watson
    return "Watson[index=" + to_string(index) + ";pos=" + pos.str() + ";moving_rule=" + moving_rule + "]";
}
MovingObjectType Watson::getObjectType() const {    // Hàm trả về loại của Watson
    return WATSON;
}

//3.5
Sherlock::Sherlock(int index, const string &moving_rule, const Position &init_pos, Map *map, int init_hp, int init_exp)
    : MovingObject(index, init_pos, map, "Sherlock"), moving_rule(moving_rule), hp((init_hp < 0) ? 0 : (init_hp > 500) ? 500 : init_hp), exp((init_exp < 0) ? 0 : (init_exp > 900) ? 900 : init_exp){}  
    // Khởi tạo Sherlock
    

Position Sherlock::getPosition() const {    // Hàm trả về vị trí của Sherlock
    return pos;
}

int Sherlock::getHP() const {   // Hàm trả về HP của Sherlock
    return hp;
}

int Sherlock::getEXP() const {  // Hàm trả về EXP của Sherlock
    return exp;
}

Position Sherlock::getNextPosition() {  // Hàm trả về vị trí tiếp theo của Sherlock
    static size_t current_index = 0;    // Khởi tạo biến static current_index
    char direction = moving_rule[current_index];    // Lấy hướng di chuyển
    current_index = (current_index + 1) % moving_rule.length();  // Cập nhật current_index

    int new_row = pos.getRow();     // Lấy hàng mới
    int new_col = pos.getCol();     // Lấy cột mới

    switch (direction) {    // Xét hướng di chuyển
        case 'L':
            new_col--;
            break;
        case 'R':
            new_col++;
            break;
        case 'U':
            new_row--;
            break;
        case 'D':
            new_row++;
            break;
    }

    Position next_pos(new_row, new_col);    // Tạo vị trí mới
    return (map->isValid(next_pos, this)) ? next_pos : Position::npos;  // Nếu vị trí mới hợp lệ thì trả về vị trí mới, ngược lại trả về Position::npos
}

void Sherlock::move() { // Hàm di chuyển của Sherlock
    Position next_pos = getNextPosition();  // Lấy vị trí tiếp theo
    if (!next_pos.isEqual(Position::npos)) {    // Nếu vị trí tiếp theo không phải Position::npos
        this->pos = next_pos;
    }
}

string Sherlock::str() const {  // Hàm trả về chuỗi biểu diễn của Sherlock
    return "Sherlock[index=" + to_string(index) + ";pos=" + pos.str() + ";moving_rule=" + moving_rule + "]";
}
MovingObjectType Sherlock::getObjectType() const {  // Hàm trả về loại của Sherlock
    return SHERLOCK;
}






//3.7
Criminal::Criminal(int index, const Position &init_pos, Map *map, Sherlock *sherlock, Watson *watson)
    : MovingObject(index, init_pos, map, "Criminal"), sherlock(sherlock), watson(watson), previous_pos(Position::npos) {    // Khởi tạo Criminal
        count1 = 0;
    }
Criminal::~Criminal() {}    // Destructor của Criminal


int Criminal::getEXP() const {  // Hàm trả về EXP của Criminal
    return 0;
}


Position Criminal::getNextPosition() {  // Hàm trả về vị trí tiếp theo của Criminal
    Position current_pos = pos;   // Lấy vị trí hiện tại
    int max_distance = 0;   // Khởi tạo max_distance
    Position next_pos = Position::npos;

    int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};  // Mảng 2 chiều lưu hướng di chuyển (lên, trái, xuống, phải)
    for (int i = 0; i < 4; ++i) {                               // Duyệt qua 4 hướng di chuyển
        int new_row = current_pos.getRow() + directions[i][0];  // Lấy hàng mới
        int new_col = current_pos.getCol() + directions[i][1];  // Lấy cột mới
        Position candidate_pos(new_row, new_col);

        if (map->isValid(candidate_pos, this)) {    // Nếu vị trí mới hợp lệ
            int distance_to_sherlock = abs(new_row - sherlock->getCurrentPosition().getRow()) + abs(new_col - sherlock->getCurrentPosition().getCol()); // Tính khoảng cách đến Sherlock
            int distance_to_watson = abs(new_row - watson->getCurrentPosition().getRow()) + abs(new_col - watson->getCurrentPosition().getCol());   // Tính khoảng cách đến Watson
            int total_distance = distance_to_sherlock + distance_to_watson;     // Tính tổng khoảng cách

            if (total_distance > max_distance) {    // Nếu tổng khoảng cách lớn hơn max_distance
                max_distance = total_distance;    // Cập nhật max_distance
                next_pos = candidate_pos;      // Cập nhật vị trí tiếp theo
            }
        }
    }

    return next_pos;
}

Position Criminal::getPreviousPosition() const {    // Hàm trả về vị trí trước đó của Criminal
    return previous_pos;
}


void Criminal::move() { // Hàm di chuyển của Criminal
    Position next_pos = getNextPosition();  // Lấy vị trí tiếp theo
    if (!next_pos.isEqual(Position::npos)) {    // Nếu vị trí tiếp theo không phải Position::npos
        count1++;   // Tăng count1 lên 1
        previous_pos = pos; // Cập nhật vị trí trước đó
        this->pos = next_pos;   // Cập nhật vị trí hiện tại
    }
}

string Criminal::str() const {  // Hàm trả về chuỗi biểu diễn của Criminal
    return "Criminal[index=" + to_string(index) + ";pos=" + pos.str() + "]";
}

MovingObjectType Criminal::getObjectType() const {  // Hàm trả về loại của Criminal
    return CRIMINAL;
}
int Criminal::getCount() const {    // Hàm trả về count1
    return count1;    
}

//3.8
ArrayMovingObject::ArrayMovingObject(int capacity) : count(0), capacity(capacity) {   // Constructor của ArrayMovingObject
    arr_mv_objs = new MovingObject *[capacity];   // Tạo mảng arr_mv_objs
}

ArrayMovingObject::~ArrayMovingObject() {}  // Destructor của ArrayMovingObject


bool ArrayMovingObject::isFull() const {    // Hàm kiểm tra xem mảng đã đầy chưa
    return count == capacity;
}

bool ArrayMovingObject::add(MovingObject *mv_obj) {   // Hàm thêm MovingObject vào mảng
    if (isFull()) {    // Nếu mảng đã đầy thì trả về false
        return false;
    }
    arr_mv_objs[count++] = mv_obj;  // Thêm MovingObject vào mảng
    return true;
}

MovingObject *ArrayMovingObject::get(int index) const {   // Hàm lấy MovingObject tại index
    if (index >= 0 && index < count) {  // Nếu index hợp lệ
        return arr_mv_objs[index];
    }
    return nullptr;
}

int ArrayMovingObject::size() const {   // Hàm trả về số lượng MovingObject trong mảng
    return count;
}

string ArrayMovingObject::str() const { // Hàm trả về chuỗi biểu diễn của ArrayMovingObject
    stringstream ss;
    ss << "ArrayMovingObject[count=" << count << ";capacity=" << capacity << ";";
    for (int i = 0; i < count; ++i) {   // Duyệt qua số lượng MovingObject
        ss << arr_mv_objs[i]->str();    // Thêm chuỗi của MovingObject vào ss
        if (i < count - 1) {
            ss << ";";
        }
    }
    ss << "]";
    return ss.str();
}


//3.9
Configuration::Configuration(const string &filepath) {  // Constructor của Configuration
    ifstream file(filepath);    // Mở file
    if (!file.is_open()) {    // Nếu không mở được file
        cerr << "Error opening configuration file: " << filepath << endl;
        return;
    }

    string line;
    while (getline(file, line)) {   // Đọc từng dòng trong file
        istringstream iss(line);
        string key, value;
        getline(iss, key, '=');
        getline(iss, value);
        
        if (key == "MAP_NUM_ROWS") {    // Nếu key là MAP_NUM_ROWS
            map_num_rows = stoi(value);
        } else if (key == "MAP_NUM_COLS") { // Nếu key là MAP_NUM_COLS
            map_num_cols = stoi(value);
        } else if (key == "MAX_NUM_MOVING_OBJECTS") {   // Nếu key là MAX_NUM_MOVING_OBJECTS
            max_num_moving_objects = stoi(value);
        } else if (key == "ARRAY_WALLS") {  // Nếu key là ARRAY_WALLS
            value = value.substr(1, value.size() - 2);  // Xóa dấu ngoặc
            istringstream ss(value);
            string pos_str;
            num_walls = 0;
            while (getline(ss, pos_str, ';')) { // Đếm số lượng walls
                num_walls++;
            }
            arr_walls = new Position[num_walls];    // Tạo mảng arr_walls
            ss.clear();     // Xóa ss
            ss.seekg(0);    // Đưa ss về vị trí đầu
            int idx = 0;    // Khởi tạo idx
            while (getline(ss, pos_str, ';')) { // Duyệt qua số lượng walls
                int row, col;
                sscanf(pos_str.c_str(), "(%d,%d)", &row, &col);   // Lấy hàng và cột của wall
                arr_walls[idx++] = Position(row, col);
            }
        } else if (key == "ARRAY_FAKE_WALLS") {   // Nếu key là ARRAY_FAKE_WALLS
            value = value.substr(1, value.size() - 2);  // Xóa dấu ngoặc
            istringstream ss(value);    // Tạo stringstream từ value
            string pos_str;    // Khởi tạo pos_str
            num_fake_walls = 0;
            while (getline(ss, pos_str, ';')) { // Đếm số lượng fake walls
                num_fake_walls++;
            }
            arr_fake_walls = new Position[num_fake_walls];  // Tạo mảng arr_fake_walls
            ss.clear();
            ss.seekg(0);
            int idx = 0;
            while (getline(ss, pos_str, ';')) { // Duyệt qua số lượng fake walls
                int row, col;
                sscanf(pos_str.c_str(), "(%d,%d)", &row, &col);  // Lấy hàng và cột của fake wall
                arr_fake_walls[idx++] = Position(row, col);  // Thêm fake wall vào mảng
            }
        } else if (key == "SHERLOCK_MOVING_RULE") {  // Nếu key là SHERLOCK_MOVING_RULE
            sherlock_moving_rule = value;
        } else if (key == "SHERLOCK_INIT_POS") {    // Nếu key là SHERLOCK_INIT_POS
            int row, col;
            sscanf(value.c_str(), "(%d,%d)", &row, &col);   // Lấy hàng và cột của Sherlock
            sherlock_init_pos = Position(row, col);
        } else if (key == "SHERLOCK_INIT_HP") {   // Nếu key là SHERLOCK_INIT_HP
            sherlock_init_hp = stoi(value); 
        } else if (key == "SHERLOCK_INIT_EXP") {    // Nếu key là SHERLOCK_INIT_EXP
            sherlock_init_exp = stoi(value);
        } else if (key == "WATSON_MOVING_RULE") {   // Nếu key là WATSON_MOVING_RULE
            watson_moving_rule = value;
        } else if (key == "WATSON_INIT_POS") {  // Nếu key là WATSON_INIT_POS
            int row, col;
            sscanf(value.c_str(), "(%d,%d)", &row, &col);   // Lấy hàng và cột của Watson
            watson_init_pos = Position(row, col);
        } else if (key == "WATSON_INIT_HP") {   // Nếu key là WATSON_INIT_HP
            watson_init_hp = stoi(value);
        } else if (key == "WATSON_INIT_EXP") {  // Nếu key là WATSON_INIT_EXP
            watson_init_exp = stoi(value);
        } else if (key == "CRIMINAL_INIT_POS") {    // Nếu key là CRIMINAL_INIT_POS
            int row, col;
            sscanf(value.c_str(), "(%d,%d)", &row, &col);   // Lấy hàng và cột của Criminal
            criminal_init_pos = Position(row, col);     // Khởi tạo vị trí của Criminal
        } else if (key == "NUM_STEPS") {    // Nếu key là NUM_STEPS
            num_steps = stoi(value);
        }
    }

    file.close();
}

Configuration::~Configuration() {   // Destructor của Configuration
    delete[] arr_walls;
    delete[] arr_fake_walls;
}

string Configuration::str() const { // Hàm trả về chuỗi biểu diễn của Configuration
    stringstream ss;    // Tạo stringstream
    ss << "Configuration[" << endl; 
    ss << "MAP_NUM_ROWS=" << map_num_rows << endl;
    ss << "MAP_NUM_COLS=" << map_num_cols << endl;
    ss << "MAX_NUM_MOVING_OBJECTS=" << max_num_moving_objects << endl;
    ss << "NUM_WALLS=" << num_walls << endl;
    ss << "ARRAY_WALLS=[";
    for (int i = 0; i < num_walls; ++i) {
        if (i > 0) ss << ";";
        ss << "(" << arr_walls[i].getRow() << "," << arr_walls[i].getCol() << ")";
    }
    ss << "]" << endl;
    ss << "NUM_FAKE_WALLS=" << num_fake_walls << endl;
    ss << "ARRAY_FAKE_WALLS=[";
    for (int i = 0; i < num_fake_walls; ++i) {
        if (i > 0) ss << ";";
        ss << "(" << arr_fake_walls[i].getRow() << "," << arr_fake_walls[i].getCol() << ")";
    }
    ss << "]" << endl;
    ss << "SHERLOCK_MOVING_RULE=" << sherlock_moving_rule << endl;
    ss << "SHERLOCK_INIT_POS=(" << sherlock_init_pos.getRow() << "," << sherlock_init_pos.getCol() << ")" << endl;
    ss << "SHERLOCK_INIT_HP=" << sherlock_init_hp << endl;
    ss << "SHERLOCK_INIT_EXP=" << sherlock_init_exp << endl;
    ss << "WATSON_MOVING_RULE=" << watson_moving_rule << endl;
    ss << "WATSON_INIT_POS=(" << watson_init_pos.getRow() << "," << watson_init_pos.getCol() << ")" << endl;
    ss << "WATSON_INIT_HP=" << watson_init_hp << endl;
    ss << "WATSON_INIT_EXP=" << watson_init_exp << endl;
    ss << "CRIMINAL_INIT_POS=(" << criminal_init_pos.getRow() << "," << criminal_init_pos.getCol() << ")" << endl;
    ss << "NUM_STEPS=" << num_steps << endl;
    ss << "]";
    return ss.str();
}



//3.10
Robot::Robot(int index, const Position &pos, Map *map, RobotType robot_type, Criminal *criminal, const string &name)
    : MovingObject(index, pos, map), robot_type(robot_type),criminal(criminal){}    // Constructor của Robot
Robot::~Robot() {}  // Destructor của Robot

Robot *Robot::create(int index, Map *map, Criminal *criminal, Sherlock *sherlock, Watson *watson) {   // Hàm tạo Robot
    int sherlock_r = sherlock->getCurrentPosition().getRow();   // Lấy hàng của Sherlock
    int sherlock_c = sherlock->getCurrentPosition().getCol();   // Lấy cột của Sherlock
    int watson_r = watson->getCurrentPosition().getRow();       // Lấy hàng của Watson
    int watson_c = watson->getCurrentPosition().getCol();       // Lấy cột của Watson
    int criminal_r = criminal->getCurrentPosition().getRow();   // Lấy hàng của Criminal
    int criminal_c = criminal->getCurrentPosition().getCol();   // Lấy cột của Criminal
    Position criminal_pos = criminal->getCurrentPosition();    // Lấy vị trí của Criminal
    
    int to_sherlock = abs(criminal_r - sherlock_r) + abs(criminal_c - sherlock_c);  // Tính khoảng cách đến Sherlock
    int to_watson = abs(criminal_r - watson_r) + abs(criminal_c - watson_c);    // Tính khoảng cách đến Watson

    int count1 = criminal->getCount();  // Lấy count1 của Criminal
    if (count1 == 2) {
        return new RobotC(index, criminal_pos, map, criminal);  // Trả về RobotC
    } else if ((count1 % 3) == 2) { // Nếu count1 chia hết cho 3 dư 2
        if (to_sherlock < to_watson) {  // Nếu khoảng cách đến Sherlock nhỏ hơn khoảng cách đến Watson
            return new RobotS(index, criminal_pos, map, S, criminal, sherlock);
        } else if (to_sherlock > to_watson) {   // Nếu khoảng cách đến Sherlock lớn hơn khoảng cách đến Watson
            return new RobotW(index, criminal_pos, map, W, criminal, watson);
        } else if (to_sherlock == to_watson) {  // Nếu khoảng cách đến Sherlock bằng khoảng cách đến Watson
            return new RobotSW(index, criminal_pos, map, SW, criminal, sherlock, watson);
        }
    }
    return nullptr;
}
MovingObjectType Robot::getObjectType() const {    // Hàm trả về loại của Robot
    return ROBOT;
}



RobotC::RobotC(int index, const Position &init_pos, Map *map, Criminal *criminal)   // Constructor của RobotC
    : Robot(index, init_pos, map, robot_type, criminal) {
    }
RobotC::~RobotC() {}    // Destructor của RobotC

int RobotC::getDistance(Sherlock *sherlock) {   // Hàm trả về khoảng cách đến Sherlock
    int sherlock_r = sherlock->getCurrentPosition().getRow();
    int sherlock_c = sherlock->getCurrentPosition().getCol();
    int robotc_r = RobotC::getCurrentPosition().getRow();
    int robotc_c = RobotC::getCurrentPosition().getCol();
    int to_sherlock = abs(robotc_r - sherlock_r) + abs(robotc_c - sherlock_c);
    return to_sherlock;
}

int RobotC::getDistance(Watson *watson) {   // Hàm trả về khoảng cách đến Watson
    int watson_r = watson->getCurrentPosition().getRow();
    int watson_c = watson->getCurrentPosition().getCol();
    int robotc_r = RobotC::getCurrentPosition().getRow();
    int robotc_c = RobotC::getCurrentPosition().getCol();
    int to_watson = abs(robotc_r - watson_r) + abs(robotc_c - watson_c);
    return to_watson;
}

Position RobotC::getNextPosition() {    // Hàm trả về vị trí tiếp theo của RobotC
    return criminal->getPreviousPosition();
};
void RobotC::move() {   // Hàm di chuyển của RobotC
    Position next_pos = getNextPosition();
    if (!next_pos.isEqual(Position::npos)) {   
        pos=next_pos;
    }
    
}
string RobotC::str() const {    // Hàm trả về chuỗi biểu diễn của RobotC
    string str = "Robot[pos=" + pos.str() + ";type=C" + ";dist=]"; 
    return str;
}
int RobotC::getDistance() const {   // Hàm trả về khoảng cách
    return 0;   
}
RobotType RobotC::getType() const { // Hàm trả về loại của RobotC
    return C;
}



RobotW::RobotW(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Watson *watson)
    : Robot(index, init_pos, map, robot_type, criminal) {   // Constructor của RobotW
        this->watson = watson;
    }
RobotW::~RobotW() {}    // Destructor của RobotW

Position RobotW::getNextPosition() {    // Hàm trả về vị trí tiếp theo của RobotW
    int watson_r = watson->getCurrentPosition().getRow();
    int watson_c = watson->getCurrentPosition().getCol();
    int r = this->getCurrentPosition().getRow();
    int c = this->getCurrentPosition().getCol();
    int temp_r = r, temp_c = c;
    int next_r = -1, next_c = -1;
    int dis = 0;
    int min = INT_MAX;
    for (int i = 0; i < 4; i++) {   // Duyệt qua 4 hướng di chuyển
        if (i == 0) {
            temp_r = r - 1;
            temp_c = c;
            dis = abs(temp_r - watson_r) + abs(temp_c - watson_c);
        } else if (i == 1) {
            temp_r = r;
            temp_c = c + 1;
            dis = abs(temp_r - watson_r) + abs(temp_c - watson_c);
        } else if (i == 2) {
            temp_r = r + 1;
            temp_c = c;
            dis = abs(temp_r - watson_r) + abs(temp_c - watson_c);
        } else if (i == 3) {
            temp_r = r;
            temp_c = c - 1;
            dis = abs(temp_r - watson_r) + abs(temp_c - watson_c);
        }
        if (dis < min && map->isValid(Position(temp_r,temp_c),this)) {  // Nếu khoảng cách nhỏ hơn min và vị trí hợp lệ
            min = dis;
            next_r = temp_r;
            next_c = temp_c;
        }
    }
    if (map->isValid(Position(next_r, next_c),this)) {  // Nếu vị trí hợp lệ
        return Position(next_r, next_c);
    } 
    return Position::npos;  // Ngược lại trả về Position::npos
}

void RobotW::move() {   // Hàm di chuyển của RobotW
    Position next_pos = getNextPosition();      // Lấy vị trí tiếp theo
    if (!next_pos.isEqual(Position::npos)) {   
        this->pos = next_pos;
    }
}

string RobotW::str() const {    // Hàm trả về chuỗi biểu diễn của RobotW
    string str = " Robot[pos=" + pos.str() + ";type=W" + ";dist=" + to_string(getDistance()) + "]"; 
    return str;
}

RobotType RobotW::getType() const {   // Hàm trả về loại của RobotW
    return W;
}

int RobotW::getDistance() const {   // Hàm trả về khoảng cách
    int watson_r = watson->getCurrentPosition().getRow();
    int watson_c = watson->getCurrentPosition().getCol();
    int robotw_r = this->getCurrentPosition().getRow();
    int robotw_c = this->getCurrentPosition().getCol();
    int dis = abs(robotw_r - watson_r) + abs(robotw_c - watson_c);
    return dis;
}

RobotS::RobotS(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Sherlock *sherlock)
    : Robot(index, init_pos, map, robot_type, criminal) {   // Constructor của RobotS
        this->sherlock = sherlock;
    }
RobotS::~RobotS() {}    // Destructor của RobotS
Position RobotS::getNextPosition() {    // Hàm trả về vị trí tiếp theo của RobotS
    int sherlock_r = sherlock->getCurrentPosition().getRow();
    int sherlock_c = sherlock->getCurrentPosition().getCol();
    int r = this->getCurrentPosition().getRow();
    int c = this->getCurrentPosition().getCol();
    int temp_r = r, temp_c = c;
    int next_r = -1, next_c = -1;
    int dis = 0;
    int min = INT_MAX;
    for (int i = 0; i < 4; i++) {   // Duyệt qua 4 hướng di chuyển
        if (i == 0) {
            temp_r = r - 1;
            temp_c = c;
            dis = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
        } else if (i == 1) {
            temp_r = r;
            temp_c = c + 1;
            dis = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
        } else if (i == 2) {
            temp_r = r + 1;
            temp_c = c;
            dis = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
        } else if (i == 3) {
            temp_r = r;
            temp_c = c - 1;
            dis = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
        }
        if (dis < min && map->isValid(Position(temp_r,temp_c),this)) {
            min = dis;
            next_r = temp_r;
            next_c = temp_c;
        }
    }
    if (map->isValid(Position(next_r, next_c),this)) {      // Nếu vị trí hợp lệ
        return Position(next_r, next_c);
    } 
    return Position::npos;
}
void RobotS::move() {       // Hàm di chuyển của RobotS
    Position next_pos = getNextPosition();
    if (!next_pos.isEqual(Position::npos)) {   
        this->pos = next_pos;
    }
}

string RobotS::str() const {    // Hàm trả về chuỗi biểu diễn của RobotS
    string str = " Robot[pos=" + pos.str() + ";type=S" + ";dist=" + to_string(getDistance()) + "]"; 
    return str;
}

RobotType RobotS::getType() const {  // Hàm trả về loại của RobotS
    return S;
}

int RobotS::getDistance() const {   // Hàm trả về khoảng cách
    int sherlock_r = sherlock->getCurrentPosition().getRow();
    int sherlock_c = sherlock->getCurrentPosition().getCol();
    int robotw_r = this->getCurrentPosition().getRow();
    int robotw_c = this->getCurrentPosition().getCol();
    int dis = abs(robotw_r - sherlock_r) + abs(robotw_c - sherlock_c);
    return dis;
}

RobotSW::RobotSW(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Sherlock *sherlock, Watson *watson)
    : Robot(index, init_pos, map, robot_type, criminal) {   // Constructor của RobotSW
        this->sherlock = sherlock;
        this->watson = watson;
    }
RobotSW::~RobotSW() {}  // Destructor của RobotSW
Position RobotSW::getNextPosition() {   // Hàm trả về vị trí tiếp theo của RobotSW
    int sherlock_r = sherlock->getCurrentPosition().getRow();
    int sherlock_c = sherlock->getCurrentPosition().getCol();
    int watson_r = watson->getCurrentPosition().getRow();
    int watson_c = watson->getCurrentPosition().getCol();
    int r = this->getCurrentPosition().getRow();
    int c = this->getCurrentPosition().getCol();
    int temp_r = r, temp_c = c;
    int next_r = -1, next_c = -1;
    int dis = 0;
    int min = INT_MAX;
    for (int i = 0; i < 8; i++) {   // Duyệt qua 8 hướng di chuyển
        // Lên trên
        if (i == 0) {
            temp_r = r - 2;
            temp_c = c;
            int to_sherlock = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
            int to_watson = abs(temp_r - watson_r) + abs(temp_c - watson_c);
            dis = to_sherlock + to_watson;
        } 
        // Phải lên
        else if (i == 1) {
            temp_r = r - 1;
            temp_c = c + 1;
            int to_sherlock = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
            int to_watson = abs(temp_r - watson_r) + abs(temp_c - watson_c);
            dis = to_sherlock + to_watson;
        }
        // Phải
        else if (i == 2) {
            temp_r = r;
            temp_c = c + 2;
            int to_sherlock = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
            int to_watson = abs(temp_r - watson_r) + abs(temp_c - watson_c);
            dis = to_sherlock + to_watson;
        } 
        // Phải xuống
        else if (i == 3) {
            temp_r = r + 1;
            temp_c = c + 1;
            int to_sherlock = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
            int to_watson = abs(temp_r - watson_r) + abs(temp_c - watson_c);
            dis = to_sherlock + to_watson;
        }
        // Xuống
        else if (i == 4) {
            temp_r = r + 2;
            temp_c = c;
            int to_sherlock = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
            int to_watson = abs(temp_r - watson_r) + abs(temp_c - watson_c);
            dis = to_sherlock + to_watson;
        }
        // Trái xuống
        else if (i == 5) {
            temp_r = r + 1;
            temp_c = c - 1;
            int to_sherlock = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
            int to_watson = abs(temp_r - watson_r) + abs(temp_c - watson_c);
            dis = to_sherlock + to_watson;
        }
        // Trái 
        else if (i == 6) {
            temp_r = r;
            temp_c = c - 2;
            int to_sherlock = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
            int to_watson = abs(temp_r - watson_r) + abs(temp_c - watson_c);
            dis = to_sherlock + to_watson;
        }
        // Trái lên 
        else if (i == 7) {
            temp_r = r - 1;
            temp_c = c - 1;
            int to_sherlock = abs(temp_r - sherlock_r) + abs(temp_c - sherlock_c);
            int to_watson = abs(temp_r - watson_r) + abs(temp_c - watson_c);
            dis = to_sherlock + to_watson;
        }
        // Tìm khoảng nhỏ nhất
        if (dis < min && map->isValid(Position(temp_r,temp_c),this)) {
            min = dis;
            next_r = temp_r;
            next_c = temp_c;
        }
    }
    if (map->isValid(Position(next_r, next_c),this)) {  // Nếu vị trí hợp lệ
        return Position(next_r, next_c);
    }
    return Position::npos;
}
string RobotSW::str() const {   // Hàm trả về chuỗi biểu diễn của RobotSW
    string str = " Robot[pos=" + pos.str() + ";type=SW" + ";dist=" + to_string(getDistance()) + "]"; 
    return str;
}
RobotType RobotSW::getType() const {    // Hàm trả về loại của RobotSW
    return SW;
}
int RobotSW::getDistance() const {  // Hàm trả về khoảng cách
    int watson_r = watson->getCurrentPosition().getRow();
    int watson_c = watson->getCurrentPosition().getCol();
    int sherlock_r = sherlock->getCurrentPosition().getRow();
    int sherlock_c = sherlock->getCurrentPosition().getCol();
    int robotsw_r = this->getCurrentPosition().getRow();
    int robotsw_c = this->getCurrentPosition().getCol();
    int to_sherlock = abs(robotsw_r - sherlock_r) + abs(robotsw_c - sherlock_c);
    int to_watson = abs(robotsw_r - watson_r) + abs(robotsw_c - watson_c);
    int dis = to_sherlock + to_watson;
    return dis;
}
void RobotSW::move() {  // Hàm di chuyển của RobotSW
    Position next_pos = getNextPosition();
    if (!next_pos.isEqual(Position::npos)) {   
        this->pos = next_pos;
    }
}

//3.11
int Character::getEXP() const { // Hàm trả về EXP của Character
    return exp;
}

void Character::setEXP(int exp) {}  // Hàm thiết lập EXP của Character

int Character::getHP() const {  // Hàm trả về HP của Character
    return hp;
}


void Character::setHP(int exp) {}   // Hàm thiết lập HP của Character

string Character::getName() const { // Hàm trả về tên của Character
    return name;
}

BaseItem::BaseItem() {} // Constructor của BaseItem


BaseItem::~BaseItem() {}    // Destructor của BaseItem


bool MagicBook::canUse(Character* obj, Robot* robot) {  // Hàm kiểm tra xem có thể sử dụng MagicBook không
    return (obj->getEXP() <= 350);
}

void MagicBook::use(Character* obj, Robot* robot) {   // Hàm sử dụng MagicBook
    if (canUse(obj, robot)) {                // Nếu có thể sử dụng MagicBook
        int expRecovered = obj->getEXP() * 0.25;
        obj->setEXP(obj->getEXP() + expRecovered);
        cout << obj->getName() << " used MagicBook and recovered " << expRecovered << " EXP." << endl;
    } else {
        cout << obj->getName() << " cannot use MagicBook at this time." << endl;
    }
}

// Hiện thực EnergyDrink class
bool EnergyDrink::canUse(Character* obj, Robot* robot) {    // Hàm kiểm tra xem có thể sử dụng EnergyDrink không
    return (obj->getHP() <= 100);
}

void EnergyDrink::use(Character* obj, Robot* robot) {
    if (canUse(obj, robot)) {   // Nếu có thể sử dụng EnergyDrink
        int hpRecovered = obj->getHP() * 0.2;
        obj->setHP(obj->getHP() + hpRecovered);
        cout << obj->getName() << " used EnergyDrink and recovered " << hpRecovered << " HP." << endl;
    } else {
        cout << obj->getName() << " cannot use EnergyDrink at this time." << endl;
    }
}

// Hiện thực FirstAid class
bool FirstAid::canUse(Character* obj, Robot* robot) {   // Hàm kiểm tra xem có thể sử dụng FirstAid không
    return (obj->getHP() <= 100 || obj->getEXP() <= 350);
}

void FirstAid::use(Character* obj, Robot* robot) {  // Hàm sử dụng FirstAid
    if (canUse(obj, robot)) {   // Nếu có thể sử dụng FirstAid
        int hpRecovered = obj->getHP() * 0.5;
        obj->setHP(obj->getHP() + hpRecovered);
        cout << obj->getName() << " used FirstAid and recovered " << hpRecovered << " HP." << endl;
    } else {
        cout << obj->getName() << " cannot use FirstAid at this time." << endl;
    }
}

// Hiện thực ExcemptionCard class
bool ExcemptionCard::canUse(Character* obj, Robot* robot) {  // Hàm kiểm tra xem có thể sử dụng ExcemptionCard không
    return (obj->getName() == "Sherlock" && obj->getHP() % 2 != 0);
}

void ExcemptionCard::use(Character* obj, Robot* robot) {    // Hàm sử dụng ExcemptionCard
    if (canUse(obj, robot)) {
        cout << obj->getName() << " used ExcemptionCard to bypass the challenge." << endl;
    } else {
        cout << obj->getName() << " cannot use ExcemptionCard at this time." << endl;
    }
}

// Hiện thực PassingCard class
PassingCard::PassingCard(int i, int j) {    // Constructor của PassingCard
    int t = (i * 11 + j) % 4;   // Tính t
    switch (t) {
        case 0:
            challenge = "RobotS";
            break;
        case 1:
            challenge = "RobotC";
            break;
        case 2:
            challenge = "RobotSW";
            break;
        case 3:
            challenge = "all";
            break;
    }
}

bool PassingCard::canUse(Character* obj, Robot* robot) {    // Hàm kiểm tra xem có thể sử dụng PassingCard không
    return (obj->getName() == "Watson" && obj->getHP() % 2 == 0);
}

void PassingCard::use(Character* obj, Robot* robot) {   // Hàm sử dụng PassingCard
    if (canUse(obj, robot)) {
        cout << obj->getName() << " used PassingCard to bypass the challenge." << endl;
    } else {
        cout << obj->getName() << " cannot use PassingCard at this time." << endl;
    }
}







//3.13
StudyPinkProgram::StudyPinkProgram(const string &config_file_path) {    // Constructor của StudyPinkProgram
    // Khởi tạo các đối tượng từ tập tin cấu hình
    ifstream configFile(config_file_path);
    if (!configFile.is_open()) {
        cerr << "Error: Unable to open configuration file" << endl;
        exit(EXIT_FAILURE);
    }

    // Đọc các thông tin từ tập tin cấu hình và khởi tạo các đối tượng tương ứng
    string line;
    while (getline(configFile, line)) {
        stringstream ss(line);
        string type;
        ss >> type;
        if (type == "Sherlock") {
            string name;
            int exp, hp, pos;
            ss >> name >> exp >> hp >> pos;
            Position init_pos(pos); // Tạo vị trí khởi tạo từ pos
            sherlock = new Sherlock(1, "moving_rule", init_pos, nullptr, hp, exp); // Thay nullptr bằng con trỏ tới Map nếu có
        } else if (type == "Watson") {
            string name;
            int exp, hp, pos;
            ss >> name >> exp >> hp >> pos;
            Position init_pos(pos); // Tạo vị trí khởi tạo từ pos
            watson = new Watson(1, "moving_rule", init_pos, nullptr, hp, exp); // Thay nullptr bằng con trỏ tới Map nếu có
        } else if (type == "Criminal") {
            string name;
            int exp, hp, pos;
            ss >> name >> exp >> hp >> pos;
            Position init_pos(pos); // Tạo vị trí khởi tạo từ pos
            criminal = new Criminal(1, init_pos, nullptr, nullptr, nullptr); // Thay nullptr bằng con trỏ tới Sherlock và Watson nếu có
        } else if (type == "Map") {
            int num_rows, num_cols;
            ss >> num_rows >> num_cols;
            map = new Map(num_rows, num_cols);
        }
    }

    // Khởi tạo mảng các đối tượng di chuyển và thêm vào các đối tượng
    arr_mv_objs = new ArrayMovingObject(10);
    arr_mv_objs->add(criminal);
    arr_mv_objs->add(sherlock);
    arr_mv_objs->add(watson);
}

bool StudyPinkProgram::isStop() const {
    // Kiểm tra các điều kiện dừng
    if (sherlock->getHP() == 0 || watson->getHP() == 0 ||
        sherlock->getCurrentPosition() == criminal->getCurrentPosition() ||
        watson->getCurrentPosition() == criminal->getCurrentPosition()) {
        return true;
    }
    return false;
}

void StudyPinkProgram::run(bool verbose) {
    // Thực hiện vòng lặp chạy các bước
    for (int istep = 0; istep < config->num_steps; ++istep) {
        // Chạy từng đối tượng di chuyển trong mảng
        for (int i = 0; i < arr_mv_objs->size(); ++i) {
            // Di chuyển đối tượng
            arr_mv_objs->get(i)->move();

            // Kiểm tra điều kiện dừng
            if (isStop()) {
                printStep(istep);
                break;
            }

            // In ra thông tin nếu verbose được bật
            if (verbose) {
                printStep(istep);
            }

            // Kiểm tra và xử lý va chạm giữa các đối tượng
            for (int j = 0; j < arr_mv_objs->size(); ++j) {
                MovingObject* obj1 = arr_mv_objs->get(i);
                MovingObject* obj2 = arr_mv_objs->get(j);
                if (obj1 != obj2 && obj1->getCurrentPosition() == obj2->getCurrentPosition()) {
                    // Xử lý va chạm giữa obj1 và obj2
                    if (Sherlock* sh = dynamic_cast<Sherlock*>(obj1)) {
                        if (RobotS* robotS = dynamic_cast<RobotS*>(obj2)) {
                            // Xử lý khi Sherlock gặp RobotS
                            if (sh->getEXP() > 400) {
                                // Sherlock giải quyết được bài toán và nhận vật phẩm từ RobotS
                                //BaseItem* item = robotS->getItem();
                                //if (item != nullptr) {
                                    //sh->addItemToBag(item);
                                //}
                                } else {
                                    // Sherlock không giải quyết được bài toán, mất 10% EXP
                                    sh->decreaseEXP(0.1);
                                }
                        } else if (RobotW* robotW = dynamic_cast<RobotW*>(obj2)) {
                            // Xử lý khi Sherlock gặp RobotW
                            // Sherlock vượt qua và nhận vật phẩm từ RobotW
                            //BaseItem* item = robotW->getItem();
                            //if (item != nullptr) {
                                //sh->addItemToBag(item);
                            //}
                        } else if (RobotSW* robotSW = dynamic_cast<RobotSW*>(obj2)) {
                            // Xử lý khi Sherlock gặp RobotSW
                            if (sh->getEXP() > 300 && sh->getHP() > 335) {
                                // Sherlock chiến thắng RobotSW và nhận vật phẩm từ RobotSW
                                //BaseItem* item = robotSW->getItem();
                                //if (item != nullptr) {
                                    //sh->addItemToBag(item);
                                //}
                                } else {
                                    // Sherlock không thắng RobotSW, mất 15% HP và 15% EXP
                                    sh->decreaseHP(0.15);
                                    sh->decreaseEXP(0.15);
                                }
                        } else if (RobotC* robotC = dynamic_cast<RobotC*>(obj2)) {
                            // Xử lý khi Sherlock gặp RobotC
                            if (sh->getEXP() > 500) {
                                // Sherlock chiến thắng RobotC và bắt được tên tội phạm
                                criminal->setCaught(true);
                            } else {
                                // Sherlock không thắng RobotC, tiêu diệt RobotC và nhận vật phẩm từ RobotC
                                //BaseItem* item = robotC->getItem();
                                //if (item != nullptr) {
                                    //sh->addItemToBag(item);
                                //}
                            }
                        } else if (FakeWall* fakeWall = dynamic_cast<FakeWall*>(obj2)) {
                            // Xử lý khi Sherlock gặp FakeWall
                        }
                    } else if (Watson* w = dynamic_cast<Watson*>(obj1)) {
                        if (RobotS* robotS = dynamic_cast<RobotS*>(obj2)) {
                            // Xử lý khi Watson gặp RobotS
                            // TODO: Xử lý logic khi Watson gặp RobotS
                        } else if (RobotW* robotW = dynamic_cast<RobotW*>(obj2)) {
                            // Xử lý khi Watson gặp RobotW
                            // TODO: Xử lý logic khi Watson gặp RobotW
                        } else if (RobotSW* robotSW = dynamic_cast<RobotSW*>(obj2)) {
                            // Xử lý khi Watson gặp RobotSW
                            // TODO: Xử lý logic khi Watson gặp RobotSW
                        } else if (RobotC* robotC = dynamic_cast<RobotC*>(obj2)) {
                            // Xử lý khi Watson gặp RobotC
                            // TODO: Xử lý logic khi Watson gặp RobotC
                        } else if (FakeWall* fakeWall = dynamic_cast<FakeWall*>(obj2)) {
                            // Xử lý khi Watson gặp FakeWall
                            // TODO: Xử lý logic khi Watson gặp FakeWall
                        }
                    }
                }
            }
        }
    }

    printResult();
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////