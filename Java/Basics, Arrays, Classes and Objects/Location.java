//Study of Encapsulation, classes, objects and this reference
//refer : EncapsulationClassObjectThis.txt
//see : EncapsulationClassObjectThis.png

class Location
{
 //attributes of a location
 float longitude, latitude;

 //operations
 void setLocation(float a, float b)
 //void setLocation(final Location this, float a, float b)
 {
  longitude = a;//this.longitude = a;
  latitude = b;//this.latitide = b;
 }

 void displayLocation()
 {
  System.out.println("Latitude : " + latitude);
  System.out.println("Longitude : " + longitude);
 }

 //execution
 public static void main(String args[])
 {
  //Create object of Location 
  Location l = new Location();

  //Use the object
  l.setLocation(12F, 18.7F);
  //setLocation(l, 12F, 18.7F);
  l.displayLocation();

 }//main
}//Location

