import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String a,b;
		a=sc.next();
		b=sc.next();
		int max,min;
		String maxlen,minlen;
		if(Integer.parseInt(a)>Integer.parseInt(b))
		{
			max=Integer.parseInt(a);
			min=Integer.parseInt(b);
			maxlen=a;
			minlen=b;
		}
		else
		{
			max=Integer.parseInt(b);
			min=Integer.parseInt(a);
			maxlen=b;
			minlen=a;
		}
		String s="";
		int l=maxlen.length()-minlen.length();
		for(int i=maxlen.length()-1;i>=0;i--)
		{
			if(i<l)
				s=Integer.toString((int)maxlen.charAt(i)-48)+s;
			else
				s=Integer.toString((int)(maxlen.charAt(i)-48)+(int)(minlen.charAt(i-l)-48))+s;
		}
		System.out.println(s);
	}
}