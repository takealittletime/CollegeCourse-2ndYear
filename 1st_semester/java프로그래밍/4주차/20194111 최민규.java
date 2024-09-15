package dicetest;

import java.security.SecureRandom; //난수 이용을 위해 추가

class Dice { //주사위 클래스
	int num; //주사위의 눈
	
	public Dice() { //생성자
		num = 6; //주사위 생성 시 처음 눈을 6으로 초기화
	}
	
	public void setroll() { //주사위를 굴리는 메소드
		SecureRandom rand = new SecureRandom(); //SecureRandom객체 rand 생성
		this.num = rand.nextInt(6)+1; // 1~6 사이의 난수로 주사위의 눈을 지정
	}
	
	
}

public class Dicetest { //주사위를 테스트하는 객체

	public static void main(String[] args) {
		int result = 0; //주사위를 굴린 횟수를 할당할 정수형 변수 result를 0으로 선언, 초기화
		
		while (true) //무한 루프
		{
			Dice a = new Dice(); //주사위 a (주사위1) 객체 생성
			a.setroll(); //주사위 a를 굴림
			
			Dice b = new Dice(); //주사위 b (주사위2) 객체 생성
			b.setroll(); //주사위 b 굴림
			
			//주사위 굴린 횟수 증가
			result += 1;
			
			//각 주사위의 눈 출력
			System.out.println("주사위1 = "+a.num+", 주사위2 = "+b.num);
			
			//주사위 두 개 눈의 합이 2인 경우 루프 종료
			if (a.num + b.num == 2)
			{
				break;
			}
			
		}
		//루프 벗어나면 횟수 출력
		System.out.println("(1,1)이 나오는데 걸린 횟수 ="+result);

	}

}
