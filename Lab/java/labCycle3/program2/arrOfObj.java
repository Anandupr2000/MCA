import java.util.*;
class Employee{
        int empid,salary;
        String name,addr;
        Employee(int id,String name,int sal,String addr){
                empid=id;
                this.name=name;
                salary=sal;
                this.addr=addr;
        }
}
class Teacher extends Employee{

        String dept,subj;
        Teacher(String d,String s,int id,String name,int sal,String addr){
                super(id,name,sal,addr);
                dept=d;
                subj=s;
        }
        void display(){
                System.out.println("ID:"+empid+"\nName:"+name+"\nSalary:"+salary+"\nAddress:"+addr+"\nDepartment:"+dept+"\nSubjects taught:"+subj+"\n");

        }
}
public class arrOfObj
{
        public static void main(String a[])
        {
                Scanner s=new Scanner(System.in);
                int n,id,salary;
                String name,address,dept,sub;
                Employee e[]=new Employee[20];
                Teacher t[]=new Teacher[20];
                System.out.println("Enter no of teachers:");
                n=s.nextInt();
                for(int i=0;i<n;i++)
                {       System.out.println("Employee "+(i+1));
                        System.out.println("Enter the emp id & name of employee:");
                        id=s.nextInt();
                        name=s.next();
                        System.out.println("Enter salary & address:");
                        salary=s.nextInt();
                        address=s.next();
                        //e[i]=new Employee(id,name,salary,address);
                        System.out.println("Teacher "+(i+1));
                        System.out.println("Enter department & subjects taught:");
                        dept=s.next();
                        sub=s.next();
                        t[i]=new Teacher(dept,sub,id,name,salary,address);

                }
                for(int i=0;i<n;i++)t[i].display();
       
        }

}