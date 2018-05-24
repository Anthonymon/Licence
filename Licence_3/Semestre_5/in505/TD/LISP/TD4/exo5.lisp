(defun lire-ecrire (entree sortie) 
	(let ((in (open entree :direction :input))
		 ((out (open sortie :direction :output :if-exists :supersede)))
		 (loop for line = (read-line in nil 'eof)
			until (eq line 'eof)
			do(if(eq (char line 0)#\%)
				nil
				(format out "~A~%" line)))
				(close in)
				(close out)
		)
		)
		)

