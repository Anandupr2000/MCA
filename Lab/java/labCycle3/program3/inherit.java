import java.util.*;
class person{
        int age;
        String name,gender,address;
        person(String name,String gender,String address,int age){
                this.name = name;
                this.gender = gender;
                this.address = address;
                this.age = age;
        }
}
class employee extends person{
        int empid,salary;
        String cName,qualification;
        employee(String name,String gender,String address,int age,int empid,String cName,String qualification,int salary){
                super(name,gender,address,age);
                this.cName = cName;
                this.empid = empid;
                this.qualification = qualification;
                this.salary = salary;
        }
}
class teacher extends employee{
        int tId;
        String subject,department;
        teacher(int tId,String subject,String department,String name,String gender,String address,int age,int empid,String cName,String qualification,int salary){
                super(name,gender,address,age,empid,cName,qualification,salary);
                this.tId = tId;
                this.subject = subject;
                this.department = department;
        }
        void display(){
                System.out.println("\tTeacher id : "+tId);
                System.out.println("\tEmployee id : "+empid);
                System.out.println("\tName : "+name);
                System.out.println("\tSubject : "+subject);
                System.out.println("\tDepartment : "+department);
                System.out.println("\tGender : "+gender);
                System.out.println("\tAddress : "+address);
                System.out.println("\tAge : "+age);
                System.out.println("\tCompany name : "+cName);
                System.out.println("\tQualification : "+qualification);
                System.out.println("\tSalary : "+salary);
        }
}
class main1{
        public static void main(String args[]){
                int n,teacherId,age,empid,salary;
                String name,gender,address,cName,subject,dept,qualification;
                Scanner input = new Scanner(System.in);
                System.out.print("\nEnter the no of teachers : ");
                n = input.nextInt();
                teacher t[] = new teacher[n];
                for(int i=0;i<n;i++){
                        teacherId =i+1;
                        System.out.println("Enter details of teacher"+(i+1));
                        System.out.println("Enter employee id : ");
                        empid = input.nextInt();
                        System.out.println("Enter name : ");
                        name = input.next();
                        System.out.println("Enter subject : ");
                        subject = input.next();
                        System.out.println("Enter department : ");
                        dept = input.next();
                        System.out.println("Enter gender : ");
                        gender = input.next();
                        System.out.println("Enter address : ");
                        address = input.next();
                        System.out.println("Enter age : ");
                        age = input.nextInt();
                        System.out.println("Enter company name : ");
                        cName = input.next();
                        System.out.println("Enter qualification : ");
                        qualification = input.next();
                        System.out.println("Enter salary : ");
                        salary = input.nextInt();
                        t[i]=new teacher(teacherId,subject,dept,name,gender,address,age,empid,cName,qualification,salary);
                        System.out.println("");
                }
                System.out.println("Details of teachers");
                for(int i=0;i<n;i++){
                        System.out.println("\n=======================================");
                        System.out.println("\tTeacher "+(i+1));
                        t[i].display();

                }
                input.close();
        }
}