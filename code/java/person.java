public class person {
    String name;
    private String age;
    protected int year;
    public int num;
    public person(String name , String age, int year, int num){
        this.name = name;
        this.age = age;
        this.year = year;
        this.num=num;
    }
    public String getAge(){
        return this.age;
    }
}
