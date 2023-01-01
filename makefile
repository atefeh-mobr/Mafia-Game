CC := g++ -std=c++11

all: mafia.out

mafia.out: main.o game.o person.o good_guys.o bad_guys.o joker.o villager.o detective.o doctor.o bulletproof.o mafia.o godfather.o silencer.o no_game_error.o not_a_player_error.o incomplete_role_error.o complete_role_error.o silenced_player_error.o dead_player_error.o joker_won_error.o sleepy_player_error.o asked_detective_error.o healed_doctor_error.o repeat_swap_error.o night_swap_error.o day_swap_error.o
	$(CC) main.o game.o person.o good_guys.o bad_guys.o joker.o villager.o detective.o doctor.o bulletproof.o mafia.o godfather.o silencer.o no_game_error.o not_a_player_error.o incomplete_role_error.o complete_role_error.o silenced_player_error.o dead_player_error.o joker_won_error.o sleepy_player_error.o asked_detective_error.o healed_doctor_error.o repeat_swap_error.o night_swap_error.o day_swap_error.o -o mafia.out

main.o: main.cpp
	$(CC) -c main.cpp

game.o: game.cpp
	$(CC) -c game.cpp

person.o: person.cpp
	$(CC) -c person.cpp

good_guys.o: good_guys.cpp
	$(CC) -c good_guys.cpp

bad_guys.o: bad_guys.cpp
	$(CC) -c bad_guys.cpp

joker.o: joker.cpp
	$(CC) -c joker.cpp

villager.o: villager.cpp
	$(CC) -c villager.cpp

detective.o: detective.cpp
	$(CC) -c detective.cpp

doctor.o: doctor.cpp
	$(CC) -c doctor.cpp

bulletproof.o: bulletproof.cpp
	$(CC) -c bulletproof.cpp

mafia.o: mafia.cpp
	$(CC) -c mafia.cpp

godfather.o: godfather.cpp
	$(CC) -c godfather.cpp

silencer.o: silencer.cpp
	$(CC) -c silencer.cpp

no_game_error.o: no_game_error.cpp
	$(CC) -c no_game_error.cpp

not_a_player_error.o: not_a_player_error.cpp
	$(CC) -c not_a_player_error.cpp

incomplete_role_error.o: incomplete_role_error.cpp
	$(CC) -c incomplete_role_error.cpp

complete_role_error.o: complete_role_error.cpp
	$(CC) -c complete_role_error.cpp

silenced_player_error.o: silenced_player_error.cpp
	$(CC) -c silenced_player_error.cpp

dead_player_error.o: dead_player_error.cpp
	$(CC) -c dead_player_error.cpp

joker_won_error.o: joker_won_error.cpp
	$(CC) -c joker_won_error.cpp	

sleepy_player_error.o: sleepy_player_error.cpp
	$(CC) -c sleepy_player_error.cpp

asked_detective_error.o: asked_detective_error.cpp
	$(CC) -c asked_detective_error.cpp	

healed_doctor_error.o: healed_doctor_error.cpp
	$(CC) -c healed_doctor_error.cpp	

repeat_swap_error.o: repeat_swap_error.cpp
	$(CC) -c repeat_swap_error.cpp

night_swap_error.o: night_swap_error.cpp
	$(CC) -c night_swap_error.cpp		

day_swap_error.o: day_swap_error.cpp
	$(CC) -c day_swap_error.cpp	

clean:
	rm *.o
	rm mafia.out
