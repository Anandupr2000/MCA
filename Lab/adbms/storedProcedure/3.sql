drop procedure if exists displayName;

delimiter |
create procedure displayName(in id int,out name varchar(20))
begin
select empName into name from employee where empId=id;
end |
delimiter ;