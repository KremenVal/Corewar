.name			""		#comment
.comment		""		#comment
						#comment
live:					#comment
	live %1				#comment
						#comment
while:					#comment
	fork %10 			#comment
	lfork %10			#comment
	ld 1, r1			#comment
	st r1, 50			#comment
	ld 0, r1			#comment
	zjmp %:live			#comment
						#comment