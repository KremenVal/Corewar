.name "Sponge"
.comment "Sponge"
						#comment
live:live%1			#comment
						#comment
while:					#comment
	fork%10 			#comment
	lfork %10			#comment
	ld 1, r1
	aff r78
	st r1,50
	ld 0, r1			#comment
	zjmp %:live			#comment
						#comment