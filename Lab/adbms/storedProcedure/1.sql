drop procedure if exists calSal;

delimiter |

create procedure calSal()
begin 
    declare flag int default 0;
    declare sal,n,id int;
    declare desig varchar(20);
    declare c1 cursor for select empId,designation,no_of_working_days from employee;
    declare continue handler for sqlstate "02000" set flag=1;
    open c1;
    repeat
        fetch c1 into id,desig,n;
        if(!flag) then
            if(desig="Programmer") then
                set sal= 1250*n;
            elseif(desig="Officer") then
                set sal= 1750*n;
            else
                set sal= 750*n; 
            end if;
            update employee set salary=sal where empid=id;
        end if;
        until flag end repeat;
    -- close c1;
end |
delimiter ;