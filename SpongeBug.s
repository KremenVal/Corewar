.name			""		#comment
.comment		""		#comment
						#comment
live:					#comment
	live %1				#comment
						#comment
while:					#comment
	fork %1 			#comment
	lfork %110			#comment
	ld 11, r1			#comment
	st r1, 50			#comment
	ld 0, r1			#comment
	zjmp %:live			#comment
						#comment
