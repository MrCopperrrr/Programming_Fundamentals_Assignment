#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////


using namespace std;
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
if (e1 < 0 || e1 > 99) {
        return -99; 
    }    
switch(e1)
    {//Trường hợp 1
        case 0:     //E1=0
            exp2 += 29;
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            break;
        case 1:     //E1=1
            exp2 += 45;
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            break;
        case 2:     //E1=2
            exp2 += 75;
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            break;
        case 3:     //E1=3 thì tổng của 3 cái trên
            exp2 += 149;
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            break;
        //Trường hợp 2
        case 4:     //E1=[4;19]
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            exp2 =(int)ceil((double)exp2+ (double)e1 / 4 + 19);
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            exp1 -= e1; //trừ e1 exp1
            exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
            break;
        case 20:      //E1=[20;49]
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            exp2 =(int)ceil((double)exp2+ (double)e1 / 9 + 21);
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            exp1 -= e1; //trừ e1 exp1
            exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
            break;
        case 50:    //E1=[50;65]
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
            exp2 =(int)ceil((double)exp2+ (double)e1 / 16 + 17);
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            exp1 -= e1; //trừ e1 exp1
            exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
            break;
        case 66:    //E1=[66;79]
        case 67:
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
            exp2 =(int)ceil((double)exp2+ (double)e1 / 4 + 19);
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;

            if (exp2 > 200) {
                exp2 =(int)ceil((double)exp2+ (double)e1 / 9 + 21);
                exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            }
            
            exp1 -= e1; //trừ e1 exp1
            exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
            break;
        case 80:    //E1=[80;99]
        case 81:
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 97:
        case 98:
        case 99:   
            exp2 =(int)ceil((double)exp2+ (double)e1 / 4 + 19);
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            
            exp2 =(int)ceil((double)exp2+ (double)e1 / 9 + 21);
            exp2 = (int)ceil((double)exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
        
            if (exp2 > 400) {   
                exp2 =(int)ceil((double)exp2+ (double)e1 / 16 + 17);
                exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
                double realnum_exp2=(double)exp2;
                realnum_exp2=realnum_exp2+realnum_exp2 * 0.15; //Watson được cộng thêm 15% ở dạng số thực
                exp2=(int)ceil(realnum_exp2);
                exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
                }
        
            exp1 -= e1; //trừ e1 exp1 
            exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
            break;
    }
if(e1 < 4){ //nếu e1<4 thì mới xảy ra trường hợp 1
    int D = e1 * 3 + exp1 * 7;    // Suy luận của Sherlock & cập nhật EXP
    if (D % 2 == 0) {     //Chẵn
        // Sherlock đoán Afghanistan -> đúng
        exp1=(int)ceil((double)exp1+((double)D/200));
        exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
    } 
    else {      //Lẻ
        // Shecklock đoán Iraq -> sai
        exp1=(int)ceil((double)exp1-((double)D/100));
        exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
    }
}
exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;  //Nếu exp1 > 600 thì ghi 600. Nếu <0 thì ghi 0. Còn lại giữ nguyên
exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;  //Tương tự 


    return exp1 + exp2;
}





// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) {
        return -99; 
    }    

    //Con đường 1
    double P1=0.0;
    int S;//VD: EXP=300
    int sqrt_exp1_low = (int)floor(sqrt(EXP1));
    int sqrt_exp1_high = sqrt_exp1_low + 1;
    int chinh_phuong_low = sqrt_exp1_low * sqrt_exp1_low;
    int chinh_phuong_high = sqrt_exp1_high * sqrt_exp1_high;

    if (abs(EXP1 - chinh_phuong_low) < abs(EXP1 - chinh_phuong_high)) { //khoảng cách đơn vị giữa số chính phương và exp1
        S = chinh_phuong_low;
    }
    else {
        S = chinh_phuong_high;
    }

    if (EXP1 >= S)
    {
        P1 = 1;
    }
    else {
        P1 = (((double)EXP1 / (double)S + 80) / 123);
    }
    
    //Con đường 2
    //E2 lẻ
    
    if(E2%2==1){
        double startM1=(double)M1; //số tiền M1 lúc đầu
        double halfstartM1=startM1/2;
        double debtM1=0.0;//biến ghi nợ

        while ( debtM1 < halfstartM1) {
        //ý 1
        if(HP1<200){    //mua đồ ăn
            HP1+=(int)ceil((double)HP1*3.0/10);
            M1=M1-150;
            debtM1=debtM1+150;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;  //giới hạn HP
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự    
            if(debtM1>halfstartM1)
            break;
            else if(M1==0)
            break;        
        }
        

        else if(HP1>=200){     //mua nước
            HP1+=(int)ceil((double)HP1*1.0/10);
            M1=M1-70;
            debtM1=debtM1+70;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;  //Tương tự 
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự  
            if(debtM1>halfstartM1)
            break;
            else if(M1==0)
            break;         
        }
        
        

        //ý 2
        if(EXP1<400){   //đi taxi
            M1=M1-200;
            debtM1=debtM1+200;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự
            EXP1+=(int)ceil((double)EXP1*13.0/100);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;  
            if(debtM1>halfstartM1)
            break;
            else if(M1==0)
            break;       
        }
        

        else if(EXP1>=400){       //đi xe ngựa
            M1=M1-120;
            debtM1=debtM1+120;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự 
            EXP1+=(int)ceil((double)EXP1*13.0/100);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1; 
            if(debtM1>halfstartM1)
            break;
            else if(M1==0)
            break;         
        }   
        

        
        //ý 3
        if(EXP1<300){   //nghe hướng dẫn
            M1=M1-100;
            debtM1=debtM1+100;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự
            EXP1-=(int)floor((double)EXP1*1.0/10);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            if(debtM1>halfstartM1)
            break;
            else if(M1==0)
            break;
        }
        
        

        else if(EXP1>=300){   //vô gia cư dẫn đi
            M1=M1-120;
            debtM1=debtM1+120;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự
            EXP1-=(int)floor((double)EXP1*1.0/10);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            if(debtM1>halfstartM1)
            break;
            else if(M1==0)
            break;
        }
        
          //Nếu exp1 > 600 thì ghi 600. Nếu <0 thì ghi 0. Còn lại giữ nguyên     
        } 
    }
    
    

    //Ngược lại nếu E2 chẵn
    
    else if(E2%2==0){
        int bien_chay=0;
        while (bien_chay<1) {
        //ý 1
        if(HP1<200){    //mua đồ ăn
            HP1+=(int)ceil((double)HP1*3.0/10);
            M1=M1-150;  
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;  //giới hạn HP
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự  
            if(M1==0)
            break;          
        }
        
        

        else if(HP1>=200){     //mua nước
            HP1+=(int)ceil((double)HP1*1.0/10);
            M1=M1-70;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;  //Tương tự 
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự   
            if(M1==0)
            break;        
        }
        
        
        
        //ý 2
        if(EXP1<400){   //đi taxi
            M1=M1-200;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự
            EXP1+=(int)ceil((double)EXP1*13.0/100);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            if(M1==0)
            break;
        }
        
        

        else if(EXP1>=400){       //đi xe ngựa
            M1=M1-120;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự
            EXP1+=(int)ceil((double)EXP1*13.0/100);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            if(M1==0)
            break;
        }
        
 
        //ý 3
        if(EXP1<300){   //nghe hướng dẫn
            M1=M1-100;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự
            EXP1-=(int)floor((double)EXP1*1.0/10);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            if(M1==0)
            break;
        } 
        
        

        else if(EXP1>=300){   //vô gia cư dẫn đi
            M1=M1-120;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;  //Tương tự
            EXP1-=(int)floor((double)EXP1*1.0/10);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            if(M1==0)
            break;
        }
        
         
        bien_chay++;
        }     
    }
    
    EXP1+=(int)ceil((double)EXP1*17.0/100);  //EXP1 tăng 17%      
    HP1-=(int)floor((double)HP1*17.0/100);  //HP1 giảm 17%
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    

    //Tính P2
    double P2=0.0;
    int S2;//VD: EXP=300
    int sqrt_exp1_low2 = (int)floor(sqrt(EXP1));
    int sqrt_exp1_high2 = sqrt_exp1_low2 + 1;
    int chinh_phuong_low2 = sqrt_exp1_low2 * sqrt_exp1_low2;
    int chinh_phuong_high2 = sqrt_exp1_high2 * sqrt_exp1_high2;

    if (abs(EXP1 - chinh_phuong_low2) < abs(EXP1 - chinh_phuong_high2)) { //khoảng cách đơn vị giữa số chính phương và exp1
        S2 = chinh_phuong_low2;
    }
    else {
        S2 = chinh_phuong_high2;
    }

    if (EXP1 >= S2)
    {
        P2 = 1.0;
    }
    else {
        P2 = (double)(((double)EXP1 / (double)S2 + 80) / 123);
    }

    //Con đường 3
    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10) {
        i = E2;
    } 
    else if(E2>=10) {
        i = (E2 / 10 + E2 % 10) % 10;
    }

    int intP3=P[i];
    double P3 =(double)intP3 / 100.0;

    if(P1==1.0 && P2==1.0 && P3==1.0){
        EXP1-=(int)floor((double)EXP1*25.0/100);
        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;  //Nếu exp1 > 600 thì ghi 600. Nếu <0 thì ghi 0. Còn lại giữ nguyên
    } 

    else{
        double P=double(P1+P2+P3)/3;
        if(P<0.5){
            EXP1+=(int)ceil((double)EXP1*15.0/100);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;  //Nếu exp1 > 600 thì ghi 600. Nếu <0 thì ghi 0. Còn lại giữ nguyên

            HP1-=(int)floor((double)HP1*15.0/100);
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;  //Tương tự
        }
        if(P>=0.5){
            EXP1+=(int)ceil((double)EXP1*2.0/10);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;  //Nếu exp1 > 600 thì ghi 600. Nếu <0 thì ghi 0. Còn lại giữ nguyên

            HP1-=(int)floor((double)HP1*1.0/10);
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;  //Tương tự
        }
    }    


    

    return HP1 + EXP1 + M1;
    
}

    




// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) {
        return -99; 
    } 
    //tính điểm taxi
    int taxi_matrix[10][10] = { 0 };	// tạo ma trận điểm taxi
    for (int i = 0; i < 10; i++){							 
	    for (int j = 0; j < 10; j++){
		  taxi_matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);   //nhập điểm vào ma trận taxi		 
		}		
	}
	
    //tìm tọa độ gặp nhau
    int m = 0, n = 0, p = 0, q = 0;       //m,n dùng để tính tọa độ, p,q là tọa độ trong ma trận
    for (int i = 0; i < 10; i++){		    //duyệt ma trận					
	    for (int j = 0; j < 10; j++){
		    if (taxi_matrix[i][j] > (E3 * 2)){					//kiểm tra có bao nhiêu số thỏa đk
			    m += 1;
			}
		}
	}
    if (m >= 10){							//kiểm tra lớn hơn 10 thì cộng hàng chục và hàng đơn vị 
	    p = m / 10 + m % 10;
	    if (p >= 10){							//kiểm tra lớn hơn 10 thì cộng hàng chục và hàng đơn vị lần 2
	        p = p / 10 + p % 10;
            if (p >= 10){							//kiểm tra lớn hơn 10 thì cộng hàng chục và hàng đơn vị lần 3
	            p = p / 10 + p % 10;
	        }
	    }
	}
    else {
        p=m;
    }

    for (int i = 0; i < 10; i++){							//duyệt ma trận 
	    for (int j = 0; j < 10; j++){
		    if (taxi_matrix[i][j] < (-E3)){    ////kiểm tra có bao nhiêu số thỏa đk				
			    n += 1;
			}
		}
	}
    if (n >= 10){				//kiểm tra lớn hơn 10 thì cộng hàng chục và hàng đơn vị			
	    q = n / 10 + n % 10;
	    if (q >= 10){			//kiểm tra lớn hơn 10 thì cộng hàng chục và hàng đơn vị lần 2				 
	        q = q / 10 + q % 10;
            if (q >= 10){			//kiểm tra lớn hơn 10 thì cộng hàng chục và hàng đơn vị lần 3			 
	            q = q / 10 + q % 10;
	        }
	    }
    }
    else{
        q=n;
    }
    //taxi_matrix[p][q]
    
    
    
    // tính điểm của Sherlock và Watson
    // gán tạm giá trị vào các đường chéo
    int max_matrix_trai = taxi_matrix[p][q];      //đường chéo trái
    int max_matrix_phai = taxi_matrix[p][q];      //đường chéo phải
    int cheo_trai_len = taxi_matrix[p][q];      //đường chéo trái hướng lên
    int cheo_trai_xuong = taxi_matrix[p][q];        //đường chéo trái hướng xuống
    int cheo_phai_len = taxi_matrix[p][q];      //đường chéo phải hướng lên
    int cheo_phai_xuong = taxi_matrix[p][q];        //đường chéo phải hướng xuống
    int max_point_2duongcheo = 0;

    for (int i = 0; p-i>=0 && q-i>=0; i++){							// 
	    if ((taxi_matrix[p - i][q - i]>= cheo_trai_len) ){	//chéo trái lên, đk kiểm soát nằm trong phạm vi ma trận
		    cheo_trai_len = taxi_matrix[p - i][q - i];      //tìm max trong đoạn đường chéo trái lên
		}
        else{
            cheo_trai_len=cheo_trai_len;
        }
    }
    for (int i = 0; p+i<=9 && q+i<=9; i++){
	    if ((taxi_matrix[p + i][q + i] >= cheo_trai_xuong) ){		//chéo trái xuống, đk kiểm soát nằm trong phạm vi ma trận
		    cheo_trai_xuong = taxi_matrix[p + i][q + i];      //tìm max trong đoạn đường chéo trái xuống
		}
        else{
            cheo_trai_xuong=cheo_trai_xuong;
        }
	}
	max_matrix_trai =(cheo_trai_len > cheo_trai_xuong) ? cheo_trai_len : cheo_trai_xuong;   //tìm max trong đoạn chéo trái

    for (int i = 0; p-i>=0 && q+i <=9; i++){							// 
	    if ((taxi_matrix[p - i][q + i] >= cheo_phai_len)){    //chéo phải lên, đk kiểm soát nằm trong phạm vi ma trận	
		    cheo_phai_len = taxi_matrix[p - i][q + i];    //tìm max trong đoạn đường chéo phải lên
		}
        else{
            cheo_phai_len=cheo_phai_len;
        }
    }
    for (int i = 0; p+i<=9 && q-i >=0; i++){
	    if ((taxi_matrix[p + i][q - i] >= cheo_phai_xuong)){		//chéo phải xuống, đk kiểm soát nằm trong phạm vi ma trận
		    cheo_phai_xuong = taxi_matrix[p + i][q - i];      //tìm max trong đoạn đường chéo phải xuống
		}
        else{
            cheo_phai_xuong=cheo_phai_xuong;
        }
	}
	max_matrix_phai =(cheo_phai_len > cheo_phai_xuong) ? cheo_phai_len : cheo_phai_xuong;   //max trong đoạn chéo phải
	
    // Điểm của Sher và Wat	
    max_point_2duongcheo =(max_matrix_trai > max_matrix_phai) ? max_matrix_trai : max_matrix_phai;     //max trong 2 đường chéo là điểm của Cher và Wat  

    // Nếu đuổi kịp hoặc không
    if (abs(taxi_matrix[p][q])>max_point_2duongcheo) {     //nếu ko đuổi kịp

        HP1 -= (int)floor((1.0/10 * (double)HP1));
        EXP1 -= (int)floor((12.0/100 * (double)EXP1));
        HP2 -= (int)floor((1.0/10 *(double) HP2));
        EXP2 -= (int)floor((12.0/100 * (double)EXP2));

        HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;  //giới hạn HP
        HP2 = (HP2 > 666) ? 666 : (HP2 < 0) ? 0 : HP2;  //giới hạn HP
        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        EXP2 = (EXP2 > 600) ? 600 : (EXP2 < 0) ? 0 : EXP2;

        
    } 
    else {      // kịp
        HP1 += (int)ceil((1.0/10 * (double)HP1));
        EXP1 += (int)ceil((12.0/100 * (double)EXP1));
        HP2 += (int)ceil((1.0/10 * (double)HP2));
        EXP2 += (int)ceil((12.0/100 *(double)EXP2));

        HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;  //giới hạn HP
        HP2 = (HP2 > 666) ? 666 : (HP2 < 0) ? 0 : HP2;  //giới hạn HP
        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        EXP2 = (EXP2 > 600) ? 600 : (EXP2 < 0) ? 0 : EXP2; 
    }
    int diem_lon_hon=(abs(taxi_matrix[p][q]) > abs(max_point_2duongcheo)) ? taxi_matrix[p][q] : max_point_2duongcheo;

    

    // Trả về điểm lớn hơn
    return diem_lon_hon ;
}
    




// Task 4
int checkPassword(const char * s, const char * email) {
    // tìm vị trí @ trong email
    const char* vi_tri_a = strchr(email, '@'); //check @ trong email //nếu có thì trả về con trỏ chỉ đến vị trí @
                                                    //stringchar là hàm tìm kiếm kí tự trong chuỗi
    // ko tìm thấy @
    if (vi_tri_a == NULL) {
        return -1; // ko tìm thấy trả về -1
    }

    // Tạo một chuỗi để lưu phần trước ký tự '@' trong email
    char se[100]; // 100 kí tự trươc @
    int se_length = vi_tri_a - email; //se_length là số lượng kí tự cần copy
    strncpy(se, email, se_length);//copy 1 lượng kí từ từ email và bỏ vào se
    se[se_length] = '\0'; // thêm null vào

    int s_length = strlen(s);   //độ dài chuỗi s
    // kiểm tra độ dài của pass
    if (s_length < 8) {     //ngắn quá
        return -1; 
    }
    else if (s_length > 20) {   //dài quá
        return -2; 
    }

    // kiểm pass có chứa chuỗi se 
    const char* vi_tri_cua_se = strstr(s, se);//tìm string se trong s
    if (vi_tri_cua_se != NULL) { //nếu ko có se trong s
        int sei = vi_tri_cua_se - s;
        return -(300 + sei); // Mật khẩu chứa chuỗi se
    }

    // kiểm pass có 2 kí tự liên tiếp giống 
    for (int sci = 0; sci < s_length - 2; ++sci) {//duyệt từng kí tự
        if (s[sci] == s[sci + 1] && s[sci] == s[sci + 2]) {//2 kí tự liên tiếp giống
            return -(400 + sci); 
        }
    }

    // kiểm kí tự đb 
    bool check_ki_tu_db = false;// chưa có kí tự đb
    for (const char* ptr = s; *ptr != '\0'; ++ptr) {//ptr là con trỏ của s
        if (*ptr == '@' || *ptr == '#' || *ptr == '%' || *ptr == '$' || *ptr == '!') {
            check_ki_tu_db = true;
            break;
        }
    }
    if (!check_ki_tu_db) {
        return -5; // Mật khẩu không chứa ký tự đặc biệt
    }

    // kiểm trong chuỗi có những kí tự bth và đb ko 
    for (int i = 0; i < s_length; ++i) {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
            s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return i; // Trả về vị trí sai
        }
    }

    return -10; // Mật khẩu hợp lệ
}





// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // đếm số lần xuất hiện pass
    int max_pass_count = 0; // số lần xuất hiện pass nhiều pass
    int pass_index = 0; // Chỉ số của mật khẩu xuất hiện nhiều nhất trong mảng

    for (int i = 0; i < num_pwds; ++i) { //duyệt pass trong array
        int dem_pass = 1; // đếm pass //start là 1

        for (int j = i + 1; j < num_pwds; ++j) { //kiểm số lần xuất hiện của pass hiện tại với các pass sau đó //chạy từ i+1 là bỏ qua pass đầu 
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) { //stringcompare so sánh pass hiện tại với pass kế tiếp 
                dem_pass++;
            }
        }

        if (dem_pass > max_pass_count || (dem_pass == max_pass_count && strlen(arr_pwds[i]) > strlen(arr_pwds[pass_index]))) {
            //pass nào xuất hiện nhiều nhất thì lấy
            //nếu có >1 pass xuât hiện nhiều nhất thì lấy pass có nhiều kí tự hơn
            pass_index = i; // Cập nhật chỉ số của mật khẩu xuất hiện nhiều nhất
            max_pass_count = dem_pass; // Cập nhật số lần xuất hiện nhiều nhất
        }
    }

    return pass_index; 
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////