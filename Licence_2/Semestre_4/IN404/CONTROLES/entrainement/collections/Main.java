
public class Main
{
    public static void main(){
        /*MyList t=new MyList();
        t.setElement("a");
        t.setElement("b");
        t.setElement("c");
        t.setElement("d");
        System.out.println(t.toString());
        
        MySet s=new MySet();
        s.setElement("b");
        s.setElement("c");
        s.setElement("d");
        s.setElement("b");
        System.out.println(s.toString());
        
        MyQueue q=new MyQueue();
        q.setElement("c");
        q.setElement("l");
        q.setElement("e");
        q.setElement("m");
        System.out.println(q.toString());*/
        
        MyMap m=new MyMap();
        m.setElement(1,"a");
        m.setElement(2,"b");
        m.setElement(3,"c");
        m.parcourirMap();
        m.listeValeurs();
    }
}
