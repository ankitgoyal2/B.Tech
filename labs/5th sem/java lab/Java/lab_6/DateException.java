

import java.util.Date;

class FineException extends Exception
{
	int fine ;
	public FineException(int fine)
	{
		this.fine = fine;
	}
	public String toString()
	{
		return "Fine for 15 days :" + fine;
	}
}

class InvalidDateException extends Exception
{
	public String toString()
	{
		return "Return Date < Issue Date" ;
	}
}

public class DateException {
	
	static Date issue_date,return_date;
	
	public static void main(String args[])
	{
		issue_date = new Date(2019,10,3);
		return_date = new Date(2019,10,20);
		try
		{
			if(return_date.before(issue_date))
			{
				throw new InvalidDateException();
			}
			
			if(return_date.getTime()-issue_date.getTime()>15*24*60*60*1000)
			{
				int fine = (int)(return_date.getTime()-issue_date.getTime())/(24*60*60*1000)*50;
				throw new FineException(fine);
			}
		}
		catch(InvalidDateException e)
		{
			System.out.print(e);
		}
		catch(FineException e)
		{
			System.out.print(e);
		}
	}

}
