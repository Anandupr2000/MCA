drop procedure if exists result;

delimiter |
create procedure result(in rno int)
begin
    declare m1,m2,m3,percentage int;
    declare status varchar(10);
    select mark1,mark2,mark3 into m1,m2,m3 from student where rollno=rno;
    set percentage = ((m1+m2+m3)*100)/300;
    if(percentage<40) then
        set status="Fail";
    else 
        set status="Pass";
    end if;
    select status;
end |
delimiter ;