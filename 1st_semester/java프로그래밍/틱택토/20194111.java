package tictactoe;

import java.util.*;//scannerŬ������ ����

public class tictactoe {

	public static void main(String[] args) {
		char[][] board=new char[3][3]; //�������� ��Ÿ���� 2���� �迭�� ����
	      int x, y;
	      
	      Scanner scan = new Scanner(System.in);
	      
	      //�������� ��Ÿ���� 2���� �迭�� �ʱ�ȭ
	      for (int i=0;i<3;i++)
	         for (int j=0;j<3;j++)
	            board[i][j]=' ';
	      
	      do
	      {
	    	     int i=0, j=0;
		         
		         int a = 0, b = 0;
		         
		         int num = 0;

	    	  //�������� �׸�
	         for(i=0;i<3;i++)
	         {
	            System.out.println(" "+board[i][0]+" | "+board[i][1]+" | "+board[i][2]);
	            
	            if(i !=2)
	               System.out.println("---|---|---");
	         
	         }
	         
	         System.out.print("���� ���� ��ǥ�� �Է��Ͻÿ�(����,����): ");
	         x=scan.nextInt();
	         y=scan.nextInt();
	         
	         //����ڰ� ���� ��ġ�� �˻�
	         if (x>2 || x<0 || y>2 || y<0||board[x][y] != ' ')
	         {
	            System.out.println("�߸��� ��ġ�Դϴ�. ");
	            continue;
	         }
	         else
	            board[x][y]='X';
	         
	         //��ǻ�Ͱ� ���� ��ġ�� �����Ѵ�.   
	         
	         //����ڰ� ���� ���� 
	         for (a = 0; a<3; a++) {
	        	 for (b = 0; b<3; b++)
	        		 if (board[a][b] == 'X')
	        		 {
	        			 num++;
	        		 }
	        	
	         }
	         
	         //����ڰ� �ϳ� �ξ��� ��
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
	         
	         //����ڰ� �� �� �̻� ���� ���
	         else
	         {
	        	 //����ڰ� ���η� 2�� ���� ���
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
	        	 
	        	 //����ڰ� ���η� 2�� ���� ���
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
	         //��ǻ�Ͱ� �̹� �� ���� ����� �� ��� �ִ� ĭ�� ��
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
	         
	       //��ǻ�Ͱ� �δ� �� �˻��� �� �α�
	         if(i<3&&j<3&&board[i][j]==' ')
	            board[i][j]='0';
	       
	         
	         
	      }
	      while (true);


	}

}
