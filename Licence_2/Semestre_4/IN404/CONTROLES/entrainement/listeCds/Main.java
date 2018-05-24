class Main
{

    public static void main(){
        Album a=new Album();
        Cd c1=new Cd("cms","zer",12);
        Cd c2=new Cd("cl","rty",17);
        a.nouveauCd(c1);
        a.nouveauCd(c2);
        a.afficheAlbum();
        a.tri();
        a.afficheAlbum();
    }
}
