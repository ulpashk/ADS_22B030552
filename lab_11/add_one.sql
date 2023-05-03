CREATE OR REPLACE PROCEDURE add_one(contact_name VARCHAR(20), contact_number VARCHAR(20))
	AS $$
	DECLARE
		is_exist BOOLEAN;
	BEGIN
		SELECT EXISTS(SELECT phonebook.number FROM phonebook WHERE contact_name = phonebook.name) INTO is_exist;
		
		IF is_exist THEN 
			UPDATE phonebook SET number = contact_number WHERE phonebook.name = contact_name;
		ELSE
			INSERT INTO phonebook (name, number) VALUES (contact_name, contact_number);
		END IF;
		
	END; $$
	LANGUAGE 'plpgsql'