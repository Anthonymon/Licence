(defun recherche-n (numerateur denominateur)
	(let ((n 2))
		(loop while( and (<= (/ 1 n) (/ numerateur denominateur))
						 (< (/ numerateur denominateur) (/ 1 (- n 1)))
					)do
			(setf n (+ n 1))
		)
		n
	)
)

(defun FunEgypt (numerateur denominateur)
	(cond
		((= denominateur 0) nil)
		(t
			(append 
				(list (recherche-n numerateur denominateur))
				(FunEgypt 
					(- (* (recherche-n numerateur denominateur) numerateur) denominateur)
					(* (recherche-n numerateur denominateur) denominateur)
				)
			)
		)
	)
)
