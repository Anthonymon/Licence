import static org.junit.Assert.*;

import org.junit.Test;

public class WordAnalyzerTester
{

   @Test
   public void test1() {
	   WordAnalyzer wa=new WordAnalyzer("aardvark");
	   char result=wa.firstRepeatedCharacter();
	   assertEquals(new Character(result),new Character('a'));
   }
   
   @Test
   public void test2() {
	   WordAnalyzer wa=new WordAnalyzer("roommate");
	   char result=wa.firstRepeatedCharacter();
	   assertEquals(new Character(result),new Character('o'));
   }
   
   @Test
   public void test3() {
	   WordAnalyzer wa=new WordAnalyzer("mate");
	   char result=wa.firstRepeatedCharacter();
	   Integer res = new Integer(result);
	   assertEquals(res.toString(), res ,new Integer(0));
	   //assertEquals(new Character(result),new Character('t'));
   }
   
   @Test
   public void test4() {
	   WordAnalyzer wa=new WordAnalyzer("test");
	   char result=wa.firstRepeatedCharacter();
	   assertEquals(new Integer(result),new Integer(0));
   }
   
}
