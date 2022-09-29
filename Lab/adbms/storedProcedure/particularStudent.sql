DROP PROCEDURE showstudent;

delimiter $$
CREATE PROCEDURE showstudent(in Id int)
begin
select * from student1 where id=Id;
end $$
delimiter ;