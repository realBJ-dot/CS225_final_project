<h1>CS 225 Final project</h1>
<h3>Haoyu Liu, Peiyuan Jin, Xinshuo Lei</h3>
<br>
<h2>Introduction</h2>
<p style = "line-height: 1.8">
This project loads airports and routes data in <a href="https://openflights.org/data.html">OpenFlight</a> dataset as a graph with airports as vertices and routes as edges, then use that graph to run algorithms. <br />
</p>  
<p style = "line-height: 1.8">
  <b>Available algorithms</b> are: <br>
  1. DFS & BFS traversal <br>
  2. Shortest path between two airports (Floyd-Warshall Algorithm) <br>
  3. Visualization (project airports and routes onto world map)<br>
</p>
<br>
<h2>Data</h2>
<p style = "line-height: 1.8">
  Data files used are located in the data folder of this repo. <br>
  Our program supports reading other data files, but it only accepts data with the same format as airports.dat and routes.dat in the OpenFlight dataset. <br>  
</p>
<p style = "line-height: 1.8">
  For the <b>airport</b> data, each entry contains the following information: <br>
  <b>Airport ID:</b> &emsp;
  Unique OpenFlights identifier for this airport. <br>
  <b>Name:</b>	&emsp;&emsp;&emsp;
  Name of airport. May or may not contain the City name.<br>
  <b>City:</b>	&emsp;&emsp;&emsp;&ensp;&nbsp;
  Main city served by airport. May be spelled differently from Name.<br>
  <b>Country:</b> &emsp; &ensp;
  Country or territory where airport is located. .<br>
  <b>IATA:</b>	&emsp;&emsp;&emsp;&ensp;
  3-letter IATA code. Null if not assigned/unknown.<br>
  <b>ICAO:</b>	&emsp;&emsp;&emsp;&nbsp;
  4-letter ICAO code. Null if not assigned.<br>
  <b>Latitude:</b> &emsp;&emsp;
  Decimal degrees, usually to six significant digits. Negative is South, positive is North.<br>
  <b>Longitude:</b>	&emsp;
  Decimal degrees, usually to six significant digits. Negative is West, positive is East.<br>
  <b>Altitude:</b> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	
  In feet.<br>
  <b>Timezone:</b>	&emsp;&nbsp;
  Hours offset from UTC. Fractional hours are expressed as decimals, eg. India is 5.5.<br>
  <b>DST:</b> &emsp;&emsp;&emsp;&emsp;
  Daylight savings time. One of E (Europe), A (US/Canada), S (South America),
    O (Australia), Z (New Zealand), N (None) or U (Unknown). <br>
  <b>Tz: </b>&emsp;&emsp;&emsp;&emsp;&ensp;&nbsp;
  database time zone	Timezone in "tz" (Olson) format, eg. "America/Los_Angeles".<br>
  <b>Type:</b> &emsp;&emsp;&emsp;&ensp;
  Type of the airport. Value "airport" for air terminals, "station" for train stations, 
    "port" for ferry terminals and "unknown" if not known. <br>
  <b>Source:</b> &emsp;&emsp;&ensp;
  Source of this data. "OurAirports" for data sourced from OurAirports, "Legacy" for old data not 
  matched to OurAirports (mostly DAFIF), "User" for unverified user contributions.<br>
</p>
 <p>
  <b> Sample airport data: </b><br>
  <i> 1, "Goroka Airport", "Goroka", "Papua New Guinea", "GKA", "AYGA", -6.081689834590001, 145.391998291, 5282, 10,  
    "U", "Pacific/Port_Moresby", "airport", "OurAirports" </i>
</p>
<p style = "line-height: 1.8">
  For the <b>routes</b> data, each entry contains the following information: <br>

  <b>Airline:</b> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&nbsp;
  2-letter (IATA) or 3-letter (ICAO) code of the airline. <br>
  <b>Airline ID:</b> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;
  Unique OpenFlights identifier for airline (see Airline). <br>
  <b>Source airport:</b> &emsp;&emsp;&emsp;&emsp;&emsp;
  3-letter (IATA) or 4-letter (ICAO) code of the source airport. <br>
  <b>Source airport ID:</b>&emsp;&emsp;&emsp;&emsp;
  Unique OpenFlights identifier for source airport (see Airport) <br>
  <b>Destination airport:</b> &emsp;&emsp;&emsp;
  3-letter (IATA) or 4-letter (ICAO) code of the destination airport. <br>
  <b>Destination airport ID:</b> &emsp;&ensp;&nbsp;
  	Unique OpenFlights identifier for destination airport (see Airport) <br>
  <b>Codeshare:</b>	"&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;
 "Y" if this flight is a codeshare, empty otherwise. <br>
  <b>Stops:</b>	&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;
  Number of stops on this flight ("0" for direct) <br>
  <b>Equipment:</b>	&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&nbsp;
  3-letter codes for plane type(s) generally used on this flight, separated by spaces <br>
</p>
<p>
  <b> Sample route data: </b><br>
  <i>2B, 410, AER, 2965, KZN, 2990, , 0, CR2</i>
</p>

<br>
<h2>Compiling, Testing, and Running</h2>
<p style = "line-height: 1.8">
  The following commands can be used to <b>compile and run the program</b>: <br>
  &emsp;&emsp;<code>make</code><br>
  &emsp;&emsp;<code>./graph</code><br>
Specific instructions of how to choose datasets and run different algorithms will be given after running the program.
  </p>
    
<p style = "line-height: 1.8">
  We have provided test cases for traversals and shortest path algorithms. The image of graphs used for testing are stored in the tests folder of this repo. <br>
  The following commands can be used to <b>run the test cases</b>: <br>
  &emsp;&emsp;<code>make test</code><br>
  &emsp;&emsp;<code>./test</code><br>

</p>
# cs225_final_project
