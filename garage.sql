DROP DATABASE IF EXISTS garage;
CREATE DATABASE garage;
\c garage

DROP ROLE IF EXISTS limited;
CREATE ROLE limited LOGIN PASSWORD 'limited762*';

DROP TABLE IF EXISTS users;
CREATE TABLE users (
  userid BIGSERIAL PRIMARY KEY NOT NULL,
  username text NOT NULL,
  firstname text NOT NULL,
  lastname text NOT NULL,
  password text NOT NULL,
  favgenre text NOT NULL DEFAULT 'none',
  favgame text NOT NULL DEFAULT 'none',
  avatarpath text NOT NULL DEFAULT 'none');

CREATE EXTENSION pgcrypto;
INSERT INTO users (username, firstname, lastname, password, favgenre, favgame, avatarpath) VALUES ('Bot', 'system', 'system', crypt('bot', gen_salt('bf')), 'FPS', 'Duck Hunt', 'avatars/m2.jpg');
INSERT INTO users (username, firstname, lastname, password, favgenre, favgame, avatarpath) VALUES ('raz', 'Ron', 'Zacharski', crypt('p00d13', gen_salt('bf')), 'Adventure', 'Zelda', 'avatars/m2.jpg');
INSERT INTO users (username, firstname, lastname, password, favgenre, favgame, avatarpath) VALUES ('ann', 'Ann', 'Hedberg', crypt('changeme', gen_salt('bf')), 'Puzzle', 'Warios Woods', 'avatars/m2.jpg');
INSERT INTO users (username, firstname, lastname, password, favgenre, favgame, avatarpath) VALUES ('lazy', 'Big', 'Easy', crypt('querty', gen_salt('bf')), 'none', 'none', 'avatars/m2.jpg');

DROP TABLE IF EXISTS creditcards;
CREATE TABLE creditcards (
  ccid BIGSERIAL PRIMARY KEY NOT NULL,
  userid int REFERENCES users(userid) NOT NULL,
  ccnumber text NOT NULL,
  cccode text NOT NULL,
  expmonth text NOT NULL,
  expyear int NOT NULL);
  

INSERT INTO creditcards (userid, ccnumber, cccode, expmonth, expyear) VALUES (1, crypt('1234567890123456', gen_salt('bf')), crypt('1234', gen_salt('bf')), 'January', 2016); 
INSERT INTO creditcards (userid, ccnumber, cccode, expmonth, expyear) VALUES (2, crypt('9234567890123456', gen_salt('bf')), crypt('4234', gen_salt('bf')), 'May', 2020); 

DROP TABLE IF EXISTS games;
CREATE TABLE games (
  gid BIGSERIAL PRIMARY KEY NOT NULL,
  title text NOT NULL,
  price decimal(10,2) NOT NULL,
  discountprice decimal(10,2) NOT NULL DEFAULT 0.00,
  onsale boolean NOT NULL DEFAULT FALSE);
  
INSERT INTO games (title, price, discountprice, onsale) VALUES ('FEAR2', 19.99, 9.99, 'TRUE');
INSERT INTO games (title, price, discountprice) VALUES ('Juniper''s Knot', 0, 0);
INSERT INTO games (title, price, discountprice) VALUES ('140', 4.99, 2.99);
INSERT INTO games (title, price, discountprice) VALUES ('Analogue: A Hate Story', 9.99, 5.99);
INSERT INTO games (title, price, discountprice, onsale) VALUES ('Antichamber', 19.99, 9.99, 'TRUE');
INSERT INTO games (title, price, discountprice) VALUES ('Cave Story', 14.99, 7.99);
INSERT INTO games (title, price, discountprice) VALUES ('Hotline Miami', 9.99, 4.99);
INSERT INTO games (title, price, discountprice) VALUES ('LIMBO', 9.99, 4.99);
INSERT INTO games (title, price, discountprice) VALUES ('Touhou Gensoukyou ~ Lotus Land Story', 29.99, 19.99);
INSERT INTO games (title, price, discountprice) VALUES ('Long Live the Queen', 9.99, 4.99);
INSERT INTO games (title, price, discountprice, onsale) VALUES ('Portal', 9.99, 4.99, 'TRUE');
INSERT INTO games (title, price, discountprice) VALUES ('Space Pirates and Zombies (S.P.A.Z.)', 9.99, 4.99);
INSERT INTO games (title, price, discountprice) VALUES ('Superbrothers: Sword & Sworcery EP', 7.99, 3.99);
INSERT INTO games (title, price, discountprice) VALUES ('Thomas Was Alone', 9.99, 4.99);
INSERT INTO games (title, price, discountprice) VALUES ('Transistor', 19.99, 11.99);
 
DROP TABLE IF EXISTS gamedetails;
CREATE TABLE gamedetails (
  gid int PRIMARY KEY REFERENCES games(gid) NOT NULL,
  gdesc text NOT NULL,
  votes int NOT NULL DEFAULT 0,
  artpath text NOT NULL); 

INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (1, 'Confront terrors both known and unknown in a explosive battle for survival with F.E.A.R 2: Project Origin for PC. This action-packed follow-up to Monolith Productions''s award-winning supernatural shooter F.E.A.R. begins where the previous game left off. This time, you''ll come up against Alma''s powers from the perspective of special forces operator Michael Becket. After an enormous explosion has devastated the city of Auburn, you''ll quickly discover that what seemed like an ordinary mission to retrieve and interrogate Genevieve Aristide is anything but.', 'css/images/img7.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (2, 'Juniper''s Knot is a short kinetic visual novel developed by Dischan Media. Created in under a month, Juniper''s Knot revolves around a lost boy and an imprisoned demon, as they help overcome each other''s obstacles through wit and memory, respectively.  In the world of Juniper''s Knot, fiends (demons) unconsciously drain the life of those around them to keep themselves alive; this results in a barren, run-down town that surrounds the manor in which the fiend is trapped.  The manner of dress, and details about the daily life of the boy would hint that the story is set around the Industrial Revolution.', 'css/images/Junipers_Knot.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (3, '140 is a platform game independently developed by Jeppe Carlsen, known for his gameplay direction for Playdead''s Limbo. The game is described as a "minimalistic platformer", using electronic music to create synesthesia as the player manipulates their avatar, a character that can take on several basic geometric shapes, through levels in time to the music. The gameplay has been compared to other similar games which involve music synchronization like Sound Shapes and the Bit.Trip series, though with difficult platforming elements comparable to games in the Mega Man series.', 'css/images/140.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (4, 'Analogue: A Hate Story is a visual novel created by independent designer and visual novelist Christine Love. It was created with the Ren''Py engine, and was first released for download on the author''s website in February 2012. A sequel set centuries after Love''s earlier work, Digital: A Love Story (2010), Analogue revolves around an unnamed investigator, who is tasked with discovering the reason for an interstellar ship''s disappearance once it reappears after 600 years. The game''s themes focus similarly around human/computer interaction, interpersonal relationships, and LGBT issues; but focus primarily on "transhumanism, traditional marriage, loneliness and cosplay."', 'css/images/Analogue_A_Hate_Story.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (5, 'Antichamber is a single-player first-person puzzle-platform video game created by Alexander Bruce. Many of the puzzles are based on phenomena that occur within impossible objects created by the game engine, such as passages that lead the player to different locations depending on which way they face, and structures that seem otherwise impossible within normal three-dimensional space. The game includes elements of psychological exploration through brief messages of advice to help the player figure out solutions to the puzzles as well as adages for real life.', 'css/images/Antichamber.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (6, 'Cave Story takes place within the cavernous interior of a floating island. The island is populated by Mimigas, a race of sentient, rabbit-like creatures.  The game focuses on an amnesiac protagonist who awakens in a cave. Through his explorations, he discovers a plot by the Doctor, a megalomaniac who intends to force the inhabitants of the cave to fight for him in his bid to conquer the world. The protagonist is thrust into the position of savior as he endeavors to defeat the Doctor.  ', 'css/images/Cave_Story.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (7, 'Hotline Miami is divided into several chapters, each of which is further broken down into several stages. At the start of most chapters, the unnamed protagonist wakes up in his apartment and listens to cryptic messages on his answering machine. These messages tell him to perform an arbitrary task at a certain location, which in each case is inferred as a metaphor for killing every person at that location, such as giving VIPs at a hotel a ''great stay'', or taking care of a ''pest infestation''. Prior to commencing a mission, the player is asked to select an animal mask to wear, each of which provides unique advantages or handicaps.', 'css/images/Hotline_Miami.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (8, 'Limbo is a 2D sidescroller, incorporating the physics system Box2D to govern environmental objects and the player character. The player guides an unnamed boy through dangerous environments and traps as he searches for his sister. The developer built the game''s puzzles expecting the player to fail before finding the correct solution. Playdead called the style of play "trial and death", and used gruesome imagery for the boy''s deaths to steer the player from unworkable solutions.', 'css/images/LIMBO.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (9, 'Following the events of the previous games, youkai soon begin to swarm the Hakurei Shrine, prompting Reimu Hakurei and Marisa Kirisame to separately head for a lake in the mountains, which appears to be the source of a tremendous power surge. The two reach the gateway underneath the lake, which teleports them to a strange Fantasy World, in which the mansion Mugenkan exists, where the mastermind supposedly is.', 'css/images/Lotus_Land_Story.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (10, 'Being a Queen is no easy job. Especially when you''re only fourteen, your mother has just died, and everyone and their pet snake is out to marry you, kill you, or worse. You must frantically learn the skills necessary to manage a country while fending off invasions, civil war, assassins, manipulative suitors, and eldritch abominations. Rule the world or die trying.', 'css/images/Long_Live_The_Queen.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (11, 'The game primarily comprises a series of puzzles that must be solved by teleporting the player''s character and simple objects using "the Aperture Science Handheld Portal Device", a device that can create inter-spatial portals between two flat planes. The player-character, Chell, is challenged by an artificial intelligence named GLaDOS (Genetic Lifeform and Disk Operating System) to complete each puzzle in the Aperture Science Enrichment Center using the portal gun with the promise of receiving cake when all the puzzles are completed. The game''s unique physics allows momentum to be retained through portals, requiring creative use of portals to maneuver through the test chambers.', 'css/images/Portal.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (12, 'Explore a randomly generated Galaxy populated with factions, enemies, missions, and items providing you with a unique experience each time you play.', 'css/images/SPAZ.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (13, 'If you''re the sort of gamer who likes unsolved mysteries and plot intepretation then you will love everything Sword & Sworcery has to offer.  The Scythian is on a woeful journey in search of the Golden Trigon. It is her purpose to tame each of the three pieces, obtain the Megatome, and put a stop to an acnient evil.  Dog is the companion of the Scythian. He accompanies the hero throughout most of the game and proves to be useful on a number of occasions. It''s unclear whether he belongs to the Scythian or Logfella.', 'css/images/Superbrothers-Sword-Sworcery-EP.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (14, 'In the game, the player controls one or more simple polygon shapes representing several out-of-control artificial intelligence entities, working with the shapes to get each to their individual end points on each level. Each shape is characterized with a unique name and personality, including the eponymous Thomas, which are conveyed to the player through the use of a narrator, voiced by Danny Wallace and whose performance earned the game a BAFTA Games Award.', 'css/images/Thomas_Was_Alone.jpg');
INSERT INTO gamedetails (gid, gdesc, artpath) VALUES (15, 'Cloudbank is a hand-drawn, utopian-variant of Blade Runner’s neon-soaked future, and the battleground for robotic evil-doers the Process. Standing in their way is Red: a pop star swinging a giant green sword that talks.  That sword is the Transistor, which not only acts at the excellent narrator of the game, but is also the key mechanical component of the game’s battle system.  Transistor is an absolute mental work-out. Kill things in the wrong order and you can make things magnitudes worse for yourself.  A haunting, ethereal soundtrack accompanies the game.', 'css/images/Transistor.jpg');
 
DROP TABLE IF EXISTS userlibrary;
CREATE TABLE userlibrary (
  gid int REFERENCES games(gid) NOT NULL,
  userid int REFERENCES users(userid) NOT NULL,
  purchasedstatus boolean NOT NULL DEFAULT FALSE,
  PRIMARY KEY (gid, userid));
  
INSERT INTO userlibrary (gid, userid) VALUES (1, 1);
INSERT INTO userlibrary (gid, userid) VALUES (2, 3);
INSERT INTO userlibrary (gid, userid) VALUES (5, 3);
INSERT INTO userlibrary (gid, userid) VALUES (7, 3);
  
GRANT SELECT ON creditcards TO limited;
GRANT INSERT ON creditcards TO limited;
GRANT UPDATE ON creditcards TO limited;
GRANT USAGE ON creditcards_ccid_seq TO limited;

GRANT SELECT ON users TO limited;
GRANT INSERT ON users TO limited;
GRANT UPDATE ON users TO limited;
GRANT USAGE ON users_userid_seq TO limited;

GRANT SELECT ON games TO limited;
GRANT INSERT ON games TO limited;
GRANT UPDATE ON games TO limited;
GRANT USAGE ON games_gid_seq TO limited;

GRANT SELECT ON gamedetails TO limited;
GRANT INSERT ON gamedetails TO limited;
GRANT UPDATE ON gamedetails TO limited;

GRANT SELECT ON userlibrary TO limited;
GRANT INSERT ON userlibrary TO limited;
GRANT UPDATE ON userlibrary TO limited;
GRANT DELETE ON userlibrary TO limited;

GRANT CONNECT ON DATABASE garage TO limited;
