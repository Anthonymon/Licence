(defun lire (fichier) 
	(with-open-file (str fichier :direction :input)
		(let ((resultat nil))
			(do ((ligne (read-line str nil 'eof)
					(read-line str nil 'eof))
				)
				((eql ligne 'eof))
				(setf resultat (append resultat (list ligne)))
				
			)
			resultat
		)
	)
)
