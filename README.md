# Enigma M3 Algorithm
In this project in try to reproduce the famous WW2 encryption device electro-mechanical encrypting procedure in C++ to practice the basic concepts of the language.

### History of the Enigma Machines
The Enigma machine is an encryption device developed and used in the early- to mid-20th century to protect commercial, diplomatic and military communication. It was employed extensively by Nazi Germany during World War II, in all branches of the German military.

By 1930, the Reichswehr had suggested that the Navy adopt the Enigma machine, citing the benefits of increased security (with the plugboard) and easier interservice communications. The Reichsmarine eventually agreed and in 1934 brought into service the Navy version of the Army Enigma, designated Funkschlüssel' or M3. While the Army used only three rotors at that time, in December 1938, the Army issued two extra rotors so that the three rotors were chosen from a set of five. In 1938, the Navy added two more rotors, and then another in 1939 to allow a choice of three rotors from a set of eight.

### Specification
* Enigma M3
	* Every machine has 3 rotor, a reflector and a plugboard.
* Rotors
	* There are 8 different type of rotor altogether.
	* Each rotor has 2 main part: a core and a ring.
	* The core has a given wiring depend on the type of the rotor.
	* The ring has one or two notch which responsible for the stepping mechanism.
		* The first rotor, on the right side, steps on each depressed key.
		* The middle rotor advances once on every time first rotor pass the notch.
		* The third, slowest, rotor, advances once on every time first rotor pass the notch.
		* The middle rotor will advance on the next step of the first rotor a second time in a row, if the middle rotor is in its own turnover position. This is called the double-step.
	* The ring and the rotor position could be set manualy.
* Reflector
	* The M3 modell could use 2 type of reflector: wide B or wide C
* Plugboard
	* There are 10 plug pair

###Links
* [Detailed technical description](http://users.telenet.be/d.rijmenants/en/enigmatech.htm)
* [Rotor and reflector details](https://en.wikipedia.org/wiki/Enigma_rotor_details)
* [Online emulator to help the development](http://enigmaco.de/enigma/enigma.html)
* [Online emulator for testing purposes](https://cryptii.com/pipes/enigma-machine)
* [Sample real-world enigma messages for test](http://wiki.franklinheath.co.uk/index.php/Enigma/Sample_Messages)

