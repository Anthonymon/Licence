/**
 * A class that analyzes words.
 */
public class WordAnalyzer
{
   /**
    * Constructs an analyzer for a given word.
    * @param aWord the word to be analyzed 
    */
   public WordAnalyzer(String aWord)
   {
      word = aWord;
   }

   /**
    * Gets the first repeated character. A character is <i>repeated</i>
    * if it occurs at least twice in adjacent positions. For example,
    * 'l' is repeated in "hollow", but 'o' is not. 
    * @return the first repeated character, or 0 if none found
    */
   public char firstRepeatedCharacter()
   {
      for (int i = 0; i < word.length() - 1; i++)
      {
         char ch = word.charAt(i);
         if (ch == word.charAt(i + 1))
            return ch;
      }
      return 0;
   }

   /**
    * Gets the first multiply occuring character. A character is <i>multiple</i>
    * if it occurs at least twice in the word, not necessarily in adjacent positions. 
    * For example, both 'o' and 'l' are multiple in "hollow", but 'h' is not. 
    * @return the first repeated character, or 0 if none found
    */
   public char firstMultipleCharacter()
   {
      for (int i = 0; i < word.length(); i++)
      {
         char ch = word.charAt(i);
         if (find(ch, i) >= 0)
            return ch;
      }
      return 0;
   }

   private int find(char c, int pos)
   {
      for (int i = pos; i < word.length(); i++)
      {
         if (word.charAt(i) == c) 
         {
            return i;
         }
      }
      return -1;
   }

   /**
    * Counts the groups of repeated characters. For example, "mississippi!!!" has 
    * four such groups: ss, ss, pp and !!!.
    * @return the number of repeated character groups 
    */
   public int countRepeatedCharacters()
   {
      int c = 0;
      for (int i = 1; i < word.length() - 1; i++)
      {
         if (word.charAt(i) == word.charAt(i + 1)) // found a repetition
         {
            if (word.charAt(i - 1) != word.charAt(i)) // it't the start
               c++;
         }
      }     
      return c;
   }

   private String word;
}
