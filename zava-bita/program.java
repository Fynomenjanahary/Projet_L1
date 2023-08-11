import java.util.*;
public class program
{
	public static void main(String[] argv){
		int a=2;
		Scanner fify = new Scanner(System.in);
		System.out.print("entrez le nombre : ");
		a = fify.nextInt();
		int somme=0;
		//somme = sommeCarre(a);
		function sommeC = new function();
		somme=sommeC.sommeCarre(a);
		System.out.println("la somme des carrées des nombres inférieurs ou égales à "+a+" est "+somme);
		somme = sommeCube(a);
		System.out.println("la somme des cubes des nombres inférieurs ou égales à "+a+" est "+somme);
		System.out.println(parite(a));
	}
	/*static int sommeCarre(int a){
		int somme=0;
		for(int i=1 ; i<=a ; i++){
			somme+=i*i;
		}
		return somme;
	}*/
	static int sommeCube(int a){
		int sommeC=0;
		int i=1;
		while(i<=a){
			sommeC+=i*i*i;
			i++;
		}
		return sommeC;
	} 
	static int parite(int a){
		if(a%2==0){
			System.out.println("le nombre "+a+" est pair");
		}
		else{
			System.out.println("le nombre "+a+" est impair");
		}
		return a;
	} 
}
