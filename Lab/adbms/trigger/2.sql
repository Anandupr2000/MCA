drop trigger if exists maxissue;
delimiter $$
create trigger maxissue before insert on issue
for each row
begin
    declare cnt int default 0;
    select count(*) into cnt from issue where memberno=new.memberno and status = 1 and new.status=1;
    if(cnt>=3) then
        signal sqlstate value '45000' set message_text = "maximum books issued !!!";
    end if;
end $$
delimiter ;