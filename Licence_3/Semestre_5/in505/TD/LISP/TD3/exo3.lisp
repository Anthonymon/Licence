(defun pos (liste &optional(rang 0))
	(cond
		((null liste) nil)
		((numberp (car liste)) (cons  (+ (car liste) rang) (pos (cdr liste) (+ 1 rang))))
		(t nil)
	)
)

(defun pos-iteratif (liste)
	(let ((res nil) (pos 0))
		(dolist (elem liste)
			(if(numberp elem)
				(setf res (append res (list (+ pos elem))))
			)
			(setf pos (+ pos 1))
		)
		res
	)
)

; (mapcar (lambda) '((1 2 3)(4 5 6)(7 8 9))) == (6 15 24)

(defun post-map (l)
	(cond
		((null l) l)
		(t
			(cons (car l) (post-map (mapcar '1+ (cdr l))))
		)
	)
)
