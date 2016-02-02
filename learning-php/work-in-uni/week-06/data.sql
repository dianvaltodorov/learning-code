CREATE TABLE majors(
	id int NOT NULL AUTO_INCREMENT,
	name VARCHAR(255) NOT NULL,
	academic_degree VARCHAR(255) NOT NULL ,
	start_year INT,
	PRIMARY KEY (id)
);

CREATE TABLE groups(
	id int NOT NULL AUTO_INCREMENT,
	major_id int NOT NULL,
	name VARCHAR(255) NOT NULL ,
	PRIMARY KEY (id),
	FOREIGN KEY (major_id) REFERENCES majors(id)
);

CREATE TABLE student
(
	id int NOT NULL AUTO_INCREMENT,
	first_name varchar(255) NOT NULL ,
	last_name varchar(255) NOT NULL ,
	faculty_number int NOT NULL,
	group_id int NOT NULL,
	PRIMARY KEY (id),
	FOREIGN KEY (group_id) REFERENCES groups(id),
	UNIQUE (faculty_number)
);

INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Software Engineering', 'bachelor', 2011);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Software Engineering', 'bachelor', 2012);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Software Engineering', 'bachelor', 2013);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Computer Science', 'bachelor', 2011);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Computer Science', 'bachelor', 2012);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Computer Science', 'bachelor', 2013);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Computer Science', 'bachelor', 2014);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Mathematics', 'bachelor', 2011);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Mathematics', 'bachelor', 2012);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Mathematics', 'bachelor', 2014);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Mathematics', 'bachelor', 2015);
INSERT INTO majors (NAME, ACADEMIC_DEGREE, Start_year) VALUES ('Mathematics', 'bachelor', 2016);

INSERT INTO groups (NAME, major_id) VALUES ("First", (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013));
INSERT INTO groups (NAME, major_id) VALUES ("Second", (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013));
INSERT INTO groups (NAME, major_id) VALUES ("Third", (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013));
INSERT INTO groups (NAME, major_id) VALUES ("Forth", (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013));
INSERT INTO groups (NAME, major_id) VALUES ("Fifth", (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013));

INSERT INTO groups (NAME, major_id) VALUES ("First", (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2011));
INSERT INTO groups (NAME, major_id) VALUES ("Second", (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2011));
INSERT INTO groups (NAME, major_id) VALUES ("Third", (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2011));
INSERT INTO groups (NAME, major_id) VALUES ("Forth", (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2011));
INSERT INTO groups (NAME, major_id) VALUES ("Fifth", (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2011));


INSERT INTO student (first_name, last_name, faculty_number, group_id) VALUES ("Dian", "Todorov", 61670, (SELECT id FROM groups WHERE name = "Second" AND major_id = (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013)));
INSERT INTO student (first_name, last_name, faculty_number, group_id) VALUES ("Pavel", "Dimitrov", 61675, (SELECT id FROM groups WHERE name = "Second" AND major_id = (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013)));
INSERT INTO student (first_name, last_name, faculty_number, group_id) VALUES ("Dimitar", "Kerezov", 61680, (SELECT id FROM groups WHERE name = "Second" AND major_id = (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013)));
INSERT INTO student (first_name, last_name, faculty_number, group_id) VALUES ("Stoyan", "Todorov", 61667, (SELECT id FROM groups WHERE name = "Second" AND major_id = (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013)));
INSERT INTO student (first_name, last_name, faculty_number, group_id) VALUES ("Ekaterina", "Goranova", 61628, (SELECT id FROM groups WHERE name = "Second" AND major_id = (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013)));
INSERT INTO student (first_name, last_name, faculty_number, group_id) VALUES ("Niki", "Novkirirshki", 61665, (SELECT id FROM groups WHERE name = "Second" AND major_id = (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013)));
INSERT INTO student (first_name, last_name, faculty_number, group_id) VALUES ("Toni", "Atanasov", 61618, (SELECT id FROM groups WHERE name = "Second" AND major_id = (SELECT id FROM majors WHERE name = "Software Engineering" AND start_year = 2013)));
