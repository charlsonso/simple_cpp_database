/* Create a new database named soci_db and use it */
CREATE DATABASE IF NOT EXISTS soci_db;
USE soci_db;

/* Create a new users table */
CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT,
    first_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL UNIQUE,
    active BOOL DEFAULT TRUE,
    PRIMARY KEY(id)
);

/* Verify the layout of the users table */
DESC users;

/* Create a new role called role_soci_dev and show default privileges */
CREATE ROLE role_soci_dev;
SHOW GRANTS FOR role_soci_dev;

/* Grant ALL privileges on the soci_db to the role and verify privileges */
GRANT ALL ON soci_db.* TO role_soci_dev;
SHOW GRANTS FOR role_soci_dev;

/* Create a new user called soci_dev1@localhost */
CREATE USER soci_dev1@localhost IDENTIFIED BY 'Secure123';

/* Apply the role to the new user and verify */
GRANT role_soci_dev TO soci_dev1@localhost;
SHOW GRANTS FOR soci_dev1@localhost USING role_soci_dev;

/* Activate all of user's roles after logging into MySQL */
SET DEFAULT ROLE ALL TO soci_dev1@localhost;
