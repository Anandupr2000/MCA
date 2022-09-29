drop procedure if exists copyTable;
drop table if exists emp;

create table if not exists emp(empId int primary key, empName varchar(20),nworking_days int,designation varchar(20));
delimiter &
create procedure copyTable()
begin 
    declare id,n,s int;
    declare ename,des varchar(20);
    declare flag int default 0;
    declare c1 cursor for select * from employee;

    declare continue handler for sqlstate "02000" set flag = 1;
    open c1;
    repeat
        fetch c1 into id,ename,n,des,s;
        if(!flag) then
            insert into emp values(id,ename,n,des);
        end if;
    until flag end repeat;
end &
delimiter ;