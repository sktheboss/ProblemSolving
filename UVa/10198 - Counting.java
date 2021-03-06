import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static int n;
	static BigInteger memo[] = new BigInteger[3010];
	static BigInteger DP(int sum){
		BigInteger i;
		if(sum==n)
			return i = BigInteger.valueOf(1);
		
		if(sum>n)
			return i= BigInteger.valueOf(0);
		
		if(memo[sum] !=  BigInteger.valueOf(-1))
			return memo[sum];
		
		i = DP(sum+1);
		i = i.add(DP(sum+1));
		i = i.add(DP(sum+2));
		i = i.add(DP(sum+3));
		
		return memo[sum] = i;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		

		while(sc.hasNextInt()){
			n = sc.nextInt();
			for (int i=0; i<3010; i++)
				memo[i] = BigInteger.valueOf(-1);
			BigInteger a = DP(0);
			System.out.println(a);
		}

	}
}
