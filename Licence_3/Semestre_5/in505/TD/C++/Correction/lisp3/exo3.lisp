(defun pos+_rec (liste)
	(if (or (not (listp liste)) (null liste))
		nil
		(and 
			(numberp (car liste))
			(if (= 1 (list-length liste))
				liste
				(append (pos+_rec (subseq liste 0 (1- (list-length liste))))
						(list (+ (car (last liste)) (1- (list-length liste))))
				)
			)
		)
	)
)


(defun pos+_it (liste)
	(if (or (not (listp liste)) (null liste))
		nil
		(let (x)
			(do ((i 0 (+ i 1)) (tmp liste (cdr tmp)))
				((null tmp) x)
				(if (numberp (car tmp))
					(setf x (append x (list (+ i (car tmp)))))
					(progn
						(format t "~A not a number" (car tmp))
						(return 'error)
					)
				)
			)
		)
	)
)

(defun pos+_map (liste)
	(if (or (not (listp liste)) (null liste))
		nil
		(let ((indice -1))
			(mapcar #'(lambda (x)
				(progn
					(setf indice (1+ indice))
					(+ x indice)
				))
				liste
			)
		)
	)
)

