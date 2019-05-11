.name		"SpongeBug"
.comment    "Who lives in the compiler down in the code? 
SpongeBug SegfaultPants! 
Lagging and quitting segfaulting is he?
SpongeBug SegfaultPants!
Who works 1 of 10 times you run him in sh? 
SpongeBug SegfaultPants!
So put in printf and try to break free!
SpongeBug SegfaultPants!
Ready?
SpongeBug SegfaultPants!
SpongeBug SegfaultPants!
SpongeBug SegfaultPants!
SpongeBuuuuuuug SegfaultPaaaaaaaants!"

loop: 
		sti r1, %:live, %1
live:
        live %0
        ld %0, r2
        zjmp %:loop

entree:	live	%42		# entree
	ld	%0,r5
	ld	%0,r5
	zjmp %:loop

tir:	sti	r1,%1, %1
	ld	%2304,r10
	ld	%1,r5
	ld	%0,r11
