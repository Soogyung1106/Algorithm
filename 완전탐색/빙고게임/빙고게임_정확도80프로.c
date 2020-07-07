#include <stdio.h>

int line = 0; //그어진 라인 

void row_is_ok(int bingo[5][5]) { //가로줄
	int count = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j] == 1) {
				count++;
				
				if (count == 5)
					line++;
			
			}else{
			  count = 0; //초기화
			  break; //그 다음 행으로
			}  
		}
		
	}

}


void column_is_ok(int bingo[5][5]) { //세로줄
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingo[j][i] == 1){
				count++;
				if (count == 5)
					line++;
			}
			else{
			  count = 0;
			  break; //그 다음 세로줄로
			} 
		}	
	}
	
}

void diagonal_is_ok(int bingo[5][5]) { //대각선
  int count = 0;
  
	//왼쪽 대각선
	for (int i = 0; i < 5; i++) { 
		if (bingo[i][i] == 1){
			count++;
			if (count == 5)
				line++;
		}else{
		  count = 0;
		  break;
		} 
	}
  
	//오른쪽 대각선
	for (int i = 0; i < 5; i++) {
		if (bingo[i][4-i] == 1){
			count++;
			if (count == 5)
				line++;
		}else break;
	}
	
}



int main() {
	int answer = 0; //사회자가 숫자를 부른 횟수
	int num_user[5][5];
	int num_cmp[5][5];
	int bingo[5][5] = { 0 }; //0으로 초기화

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d ", &num_user[i][j]);
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d ", &num_cmp[i][j]);
		}
	}


	//빙고 
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
		  answer++;
		  
			
			//찾기
			int a; int b;
		
			for(a=0;a<5;a++){
        for(b=0;b<5;b++){
          
          if(num_cmp[i][j] == num_user[a][b]){ //찾았음
          
            bingo[a][b] = 1;
				    row_is_ok(bingo); //가로줄
				    column_is_ok(bingo); //세로줄
				    diagonal_is_ok(bingo);  //대각선줄
				  
				    if (line >= 3) { //빙고
					    printf("%d", answer);
					    return 0;
				    }else{
				      line = 0; //초기화
				      goto EXIT; //이중포문 빠져나가기
				    }
				    
          }//end if
          
        }//end for1
			}//end for2
			
			EXIT:
			  int exit = 0;
			
		}
	}
	
}