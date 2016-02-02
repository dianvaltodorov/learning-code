CREATE DATABASE courses;
USE courses;

CREATE TABLE students(
	id INT NOT NULL AUTO_INCREMENT,
	name VARCHAR(50),
	PRIMARY KEY (id)
);

CREATE TABLE course
(
	id INT NOT NULL AUTO_INCREMENT,
	title VARCHAR(50),
	description VARCHAR(100),
	lecturer VARCHAR(50),
	PRIMARY KEY (id)
);

CREATE TABLE comments(
	id INT NOT NULL AUTO_INCREMENT,
	course_id INT NOT NULL,
	student_id INT NOT NULL ,
	comments VARCHAR(100),
	PRIMARY KEY (id),
	FOREIGN KEY (course_id) REFERENCES students(id),
	FOREIGN KEY (student_id) REFERENCES course(id)
);

INSERT INTO course (title, description, lecturer) VALUES ("www-tech", "Introduction to the web technologies", "Petrov");
INSERT INTO course (title, description, lecturer) VALUES ("artificial intelligence", "Intro to AI", "Koichev");
INSERT INTO course (title, description, lecturer) VALUES ("Programming with Python", "Course about Programming with the python language", "Bachiiski");
INSERT INTO course (title, description, lecturer) VALUES ("Functional Programming", "Scheme, Haskell party with Functional languages", "Trifonov");
INSERT INTO course (title, description, lecturer) VALUES ("Network programming in java", "Intro to network programming", "Petrov");

INSERT INTO students (name) VALUES ("Dian");
INSERT INTO students (name) VALUES ("Pavel");
INSERT INTO students (name) VALUES ("Dimitar");
INSERT INTO students (name) VALUES ("Preslav");
INSERT INTO students (name) VALUES ("Bobi");
INSERT INTO students (name) VALUES ("Niki");
INSERT INTO students (name) VALUES ("Stan");

INSERT INTO comments (course_id, student_id, comments) VALUES ((SELECT id FROM course WHERE title = "www-tech"), (SELECT id FROM students WHERE name = "Dian"), "Awesome Course, but") ;
INSERT INTO comments (course_id, student_id, comments) VALUES ((SELECT id FROM course WHERE title = "www-tech"), (SELECT id FROM students WHERE name = "Pavel"), "Yolo Course") ;
INSERT INTO comments (course_id, student_id, comments) VALUES ((SELECT id FROM course WHERE title = "www-tech"), (SELECT id FROM students WHERE name = "Niki"), "Hello") ;
-- TOOD: не го разбирам това тук
INSERT INTO comments (course_id, student_id, comments) VALUES ((SELECT id FROM course WHERE title = "www-tech"), (SELECT id FROM students WHERE name = "Pavel"), "In the eye") ;
INSERT INTO comments (course_id, student_id, comments) VALUES ((SELECT id FROM course WHERE title = "www-tech"), (SELECT id FROM students WHERE name = "Dian"), "Dino rangers") ;
INSERT INTO comments (course_id, student_id, comments) VALUES ((SELECT id FROM course WHERE title = "www-tech"), (SELECT id FROM students WHERE name = "Pavel"), "High Fly line") ;
