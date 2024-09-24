package oslab;


public class Dekker{
    int turn=1;
    int c1=1, c2=1;
    int i=0,j=1;
    //CSC variables
    int counter=0;// counter for giving processes a upper bound 
    int cscVar=13;
    private class ITh extends Thread{ // process thread for i
        public void run(){
                try{
                    do{
                        /*flag[i]= true;
                        turn=j;
                        while(flag[j]&&turn==j);// wait for j to finish
                        //critical section*/
                    	c1=0;
                    	while(c2==0)
                    	{
                    		if(turn==j)
                    		{
                    			c1=1;
                    			while(turn==j);
                    			c1=0;
                    		}
                    	}
                        System.out.println("I is in critical section");
                        cscVar++;
                        System.out.println(cscVar);
                        counter++;
                        System.out.println("counter is "+counter+"\n___________");
                        //
                        turn=j;
                        c1=1;
                        //remainder section
                    }while(counter<100); // 100 is upper bound, to remove infinite looping
                }
                catch(Exception ex){
                    ex.printStackTrace();
                }
            }
        }
    private class JTh extends Thread{ // process thread for j
            public void run(){
                try{
                    do{
                        /*flag[j]= true;
                        turn=i;
                        while(flag[i]&&turn==i);// wait for i to finish
                        //critical section*/
                    	c2=0;
                    	while(c1==0)
                    	{
                    		if(turn==i)
                    		{
                    			c2=1;
                    			while(turn==i);
                    			c2=0;
                    		}
                    	}
                        System.out.println("J is in critical section");
                        cscVar--;
                        System.out.println(cscVar);
                        counter++;
                        System.out.println("counter is "+counter+"\n___________");
                        //
                        turn=i;
                        c2=1;
                        //remainder section
                    }while(counter<100); // 100 is upper bound, to remove infinite looping
                }
                catch(Exception ex){
                    ex.printStackTrace();
                }
            }
        }
    public Dekker(){
        System.out.println("Starting Threads/Processes");
        Thread I= new ITh();
        Thread J = new JTh();
        I.start(); //start process i
        J.start(); //start process j
    }
        public static void main(String[] args){
        Dekker cSec = new Dekker();
    }
}