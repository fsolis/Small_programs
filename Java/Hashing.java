import java.util.*;

public class Hashing 
{
	public static String passwrdHash(String password,int salt)
	{
		char c;
		int n;
		String temp = "",temper2 = "";
		for(int i = 0;i<password.length();i++)
		{
			c = password.charAt(i);
			n = c * salt;
			temper2 = Integer.toString(n);
			temp = temp + temper2;
		}
		System.out.println(temp);
		return temp;
	}

	public static int getSalt()
	{
		Random generator = new Random();
		int salt;
	
		salt = generator.nextInt(1000);
	
		return salt;
	}
	
	public static boolean validateUsrName(String usrName)
	{
		int size = usrName.length();
		char c;
		for(int i = 0; i <size;i++)
		{
			c = usrName.charAt(i);
			if(!Character.isDefined(c))
			{
				return false;
			}
		}
		
		return true;
	}
	
	public static boolean validatePasswrd(String passwrd)
	{
		int size = passwrd.length();
		char c;
		boolean digit = false;
		if(size < 8)
		{
			return false;
		}
		for(int i = 0; i < size;i++)
		{
			c = passwrd.charAt(i);
			if(!Character.isLetter(c))
			{
				if(Character.isDigit(c))
				{
					digit = true;
				}
				else
				{
					return false;
				}
			}
		}
		
		if(digit == true)
		{
			return true;
		}
		return false;
	}
	
	public static void main() 
	{
		Scanner key = new Scanner(System.in);
		char ans = 'y';
		  String inputName, inputPassword,temp;
		  Boolean found;
		  String [] usrname, passwrd;
		  usrname = new String[10];
		  passwrd = new String[10];
		  int[] salt;
		  salt = new int[10];
		  for(int i = 0; i< 10;i++)
		  {
		  	usrname[i] = "";
		  	passwrd[i] = "";
		  	salt[i] = 0;
		  }
		  while(ans == 'y' || ans == 'Y')
		  {
		  	do
		  	{
		  		found = false;
		  		System.out.print( "Enter Usrname: ");
		  		inputName = key.next();
		  		for(int i = 0; i< 10;i++)
		  		{
		  			if(inputName.compareTo(usrname[i]) == 0)
		  			{
		  				System.out.print( "Username already exists");
		  				found = true;
		  			}
		  		}
		  	}while(found == true);
		  	
		  	System.out.print("Enter a Password: ");
		  	inputPassword = key.next();
		  	
		  	for(int i = 0;i<10;i++)
		  	{
		  		if(usrname[i] == "")
		  		{
		  			usrname[i] = inputName;
		  			salt[i] = getSalt();
		  			passwrd[i] = passwrdHash(inputPassword,salt[i]);
		  			break;
		  		}
		  	
		  	}
		  	System.out.print("Enter another user? (y/n) ");
		  	temp= key.next();
		  	ans = temp.charAt(0);
		  	
		  	}

		  	System.out.print("Would you like to log in? (y/n)");
		  	temp= key.next();
		  	ans = temp.charAt(0);
		  	int index = 0;
		  	boolean valid = false;
		  while(ans == 'y' || ans == 'Y')
		  {
		  		do
		  		{
		  			found = false;
		  			System.out.print( "Enter Usrname: ");
		  			inputName = key.next();
		  			for(int i = 0; i< 10;i++)
		  			{
		  				if(inputName.compareTo(usrname[i]) == 0)
		  				{
		  					index = i;
		  					found = true;
		  					break;
		  				}
		  			}
		  			if(found == false)
		  			{
		  				System.out.println("User not found.");
		  			}
		  		}while(found == false);
		  	
		  		System.out.print("Enter a Password: ");
		  		inputPassword = key.next();
		  		String temppass;
		  	
		  		while(valid == false)
		  		{
		  			temppass = passwrdHash(inputPassword,salt[index]);
		  			if(passwrd[index].compareTo(temppass) == 0)
		  			{
		  				valid = true;
		  				System.out.println("you are now logged in" );
		  			}
		  			else
		  			{
		  				System.out.println("Invalid Passord");
		  				System.out.print("Enter a Password: ");
			  		inputPassword = key.next();
		  			}
		  			
		  		}
		  		System.out.print("Would you like to log out? (y/n) ");
		  		temp= key.next();
		  		ans = temp.charAt(0);
		  		if(ans == 'y' || ans == 'Y')
		  		{	
		  			System.out.println("You are now Logged off.");
		  		}
		  	}
		  key.close();
	}
}

