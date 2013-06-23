use netagyan;
create table details (id int(11) primary key auto_increment not null,question text,query text);
insert into details(question, query) ("Ministers with criminal cases", "select * from details where criminal_case_count > 0");
insert into details(question, query) ("Ministers with more than 10 criminal cases", "select * from details where criminal_case_count > 10");
insert into details(question, query) ("Ministers educational qualification", "select candidate,education from details");
insert into details(question, query) ("Ministers with total assets more than 1Cr", "select * from details where total_assets >= 10000000");
insert into details(question, query) ("Ministers with total assets more than 10Cr", "select * from details where total_assets >= 100000000");
insert into details(question, query) ("Ministers who have not given pan card details", "select * from details where pan_given = 'N'");
insert into details(question, query) ("Ministers from BJP", "select * from details where party = 'bjp'");
insert into details(question, query) ("Ministers who are post graduates", "select * from details where education = 'post_graduate'");
insert into details(question, query) ("Ministers who have doctorate", "select * from details where education = 'doctorate'");
insert into details(question, query) ("Indipendent Candidates", "select * from details where party = 'ind'");

