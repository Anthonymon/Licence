(defun plus-grand (arg)
	(cond 
		((not(boundp 'preced)) 
			(progn
				(setf preced arg)
				nil
			)
		)
		((< preced arg)
			(progn
				(setf preced arg)
				t
			)
		)
		(t
			(progn
				(setf preced arg)
				nil
			)
		)
	)
)

