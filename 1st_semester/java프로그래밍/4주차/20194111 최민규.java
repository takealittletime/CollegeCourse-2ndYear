package dicetest;

import java.security.SecureRandom; //���� �̿��� ���� �߰�

class Dice { //�ֻ��� Ŭ����
	int num; //�ֻ����� ��
	
	public Dice() { //������
		num = 6; //�ֻ��� ���� �� ó�� ���� 6���� �ʱ�ȭ
	}
	
	public void setroll() { //�ֻ����� ������ �޼ҵ�
		SecureRandom rand = new SecureRandom(); //SecureRandom��ü rand ����
		this.num = rand.nextInt(6)+1; // 1~6 ������ ������ �ֻ����� ���� ����
	}
	
	
}

public class Dicetest { //�ֻ����� �׽�Ʈ�ϴ� ��ü

	public static void main(String[] args) {
		int result = 0; //�ֻ����� ���� Ƚ���� �Ҵ��� ������ ���� result�� 0���� ����, �ʱ�ȭ
		
		while (true) //���� ����
		{
			Dice a = new Dice(); //�ֻ��� a (�ֻ���1) ��ü ����
			a.setroll(); //�ֻ��� a�� ����
			
			Dice b = new Dice(); //�ֻ��� b (�ֻ���2) ��ü ����
			b.setroll(); //�ֻ��� b ����
			
			//�ֻ��� ���� Ƚ�� ����
			result += 1;
			
			//�� �ֻ����� �� ���
			System.out.println("�ֻ���1 = "+a.num+", �ֻ���2 = "+b.num);
			
			//�ֻ��� �� �� ���� ���� 2�� ��� ���� ����
			if (a.num + b.num == 2)
			{
				break;
			}
			
		}
		//���� ����� Ƚ�� ���
		System.out.println("(1,1)�� �����µ� �ɸ� Ƚ�� ="+result);

	}

}
