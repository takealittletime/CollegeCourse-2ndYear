package tictactoe;

import java.util.*;//scanner클래스를 포함

public class tictactoe {

	public static void main(String[] args) {
		char[][] board=new char[3][3]; //게임판을 나타내는 2차원 배열을 생성
	      int x, y;
	      
	      Scanner scan = new Scanner(System.in);
	      
	      //게임판을 나타내는 2차원 배열을 초기화
	      for (int i=0;i<3;i++)
	         for (int j=0;j<3;j++)
	            board[i][j]=' ';
	      
	      do
	      {
	    	     int i=0, j=0;
		         
		         int a = 0, b = 0;
		         
		         int num = 0;

	    	  //게임판을 그림
	         for(i=0;i<3;i++)
	         {
	            System.out.println(" "+board[i][0]+" | "+board[i][1]+" | "+board[i][2]);
	            
	            if(i !=2)
	               System.out.println("---|---|---");
	         
	         }
	         
	         System.out.print("다음 수의 좌표를 입력하시오(세로,가로): ");
	         x=scan.nextInt();
	         y=scan.nextInt();
	         
	         //사용자가 놓은 위치를 검사
	         if (x>2 || x<0 || y>2 || y<0||board[x][y] != ' ')
	         {
	            System.out.println("잘못된 위치입니다. ");
	            continue;
	         }
	         else
	            board[x][y]='X';
	         
	         //컴퓨터가 놓을 위치를 결정한다.   
	         
	         //사용자가 놓은 개수 
	         for (a = 0; a<3; a++) {
	        	 for (b = 0; b<3; b++)
	        		 if (board[a][b] == 'X')
	        		 {
	        			 num++;
	        		 }
	        	
	         }
	         
	         //사용자가 하나 두었을 때
	         if (num == 1 )
	         { 
	        	 i = x+1;
	        	 j = y+1;
	        	 
	        	 if (x == 0)
	        		 i=x+1;
	        	 if (y ==0)
	        		 j=y+1;
	        	 if(x == 2)
	        		 i=x-1;
	        	 if(y==2)
	        		 j=y-1;
	         }
	         
	         //사용자가 두 개 이상 놓은 경우
	         else
	         {
	        	 //사용자가 세로로 2개 놓은 경우
	        	 if ( x >0 && board[x-1][y] == 'X' )
	        	 {
	        		 j = y;
	        		 if (x == 1)
	        		 {
	        			 i=2;
	        		 }
	        		 
	        		 else if (x==2)
	        		 {
	        			 i = 0;
	        		 }
	        	 }
	        	 
	        	 else if (x<2&&board[x+1][y] == 'X' )
	        	 {
	        		 j = y;
	        		 if (x == 0)
	        		 {
	        			 i=2;
	        		 }
	        		 
	        		 else if (x==1)
	        		 {
	        			 i = 0;
	        		 }
	        	 }
	        	 
	        	 //사용자가 가로로 2개 놓은 경우
	        	 else if ( y>0&&board[x][y-1] == 'X')
	        	 {
	        		 i = x;
	        		 if (y==2)
	        		 {
	        			 j = 0;
	        		 }
	        		 
	        		 if (y==1)
	        		 {
	        			 j = 2;
	        		 }
	        	 }
	        	 
	        	 else if (y<2&&board[x][y+1] == 'X')
	        	 {
	        		 i = x;
	        		 if (y==0)
	        		 {
	        			 j = 2;
	        		 }
	        		 
	        		 if (y==1)
	        		 {
	        			 j = 0;
	        		 }
	        	 }
	        	 
	        	 else if (y==2 && board[x][y-2]=='X')
	        	 {
	        		 i = x;
	        		 j = y-1;
	        	 }
	        	 
	        	 else if (y == 0 && board[x][y+2] =='X')
	        	 {
	        		 i = x;
	        		 j = y+1;
	        	 }
	        	 
	        	 else if (x==0&&board[x+2][y] == 'X')
	        	 {
	        		 j=y;
	        		 i=x+1;
	        	 }
	        	 
	        	 else if (x==2&&board[x-2][y] == 'X')
	        	 {
	        		 j = y;
	        		 i = x-1;
	        	 }
	         }
	         //컴퓨터가 이미 둔 곳을 골랐을 때 비어 있는 칸에 둠
	         if (i<0||j<0||i>2||i>2||board[i][j] != ' ')
	         {
	        	 for (a = 0; a < 3; a++)
	        	 {
	        		 for (b = 0; b<3; b++)
	        		 {
	        			 if (board[a][b] == ' ')
	        			 {
	        				 i=a; j=b;
	        			 }
	        		 }
	        	 }
	         }
	         
	       //컴퓨터가 두는 곳 검사한 후 두기
	         if(i<3&&j<3&&board[i][j]==' ')
	            board[i][j]='0';
	       
	         
	         
	      }
	      while (true);


	}

}
