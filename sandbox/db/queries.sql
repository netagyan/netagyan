use netagyan;
create table query(id int(11) primary key auto_increment not null,question text,query text);
insert into query(question, query)  values ("Ministers with criminal cases", "select * from details where criminal_case_count > 0");
insert into query(question, query)  values("Ministers with more than 10 criminal cases", "select * from details where criminal_case_count > 10");
insert into query(question, query)  values("Ministers with total assets more than 1Cr", "select * from details where total_assets >= 10000000");
insert into query(question, query)  values("Ministers with total assets more than 10Cr", "select * from details where total_assets >= 100000000");
insert into query(question, query)  values("Ministers who have not given pan card details", "select * from details where pan_given = 'N'");
insert into query(question, query)  values("Ministers from BJP", "select * from details where party = 'bjp'");
insert into query(question, query)  values("Ministers who are post graduates", "select * from details where education = 'post_graduate'");
insert into query(question, query)  values("Ministers who have doctorate", "select * from details where education = 'doctorate'");
insert into query(question, query)  values("Indipendent Candidates", "select * from details where party = 'ind'");

