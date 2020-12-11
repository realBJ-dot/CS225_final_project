# peiyuan3-haoyul4-xinshuo3
<pre>
Final Project

The dataset we used is OpenFlight. Link: https://openflights.org/data.html. The datasets in this program are stored in /data.

This program only accepts data with the same format as airports.dat and routes.dat in the OpenFlight dataset.

For the airport data, each entry contains the following information:

  Airport ID:	Unique OpenFlights identifier for this airport.
  Name:	Name of airport. May or may not contain the City name.
  City:	Main city served by airport. May be spelled differently from Name.
  Country:	Country or territory where airport is located. See Countries to cross-reference to ISO 3166-1 codes.
  IATA:	3-letter IATA code. Null if not assigned/unknown.
  ICAO:	4-letter ICAO code. Null if not assigned.
  Latitude: Decimal degrees, usually to six significant digits. Negative is South, positive is North.
  Longitude:	Decimal degrees, usually to six significant digits. Negative is West, positive is East.
  Altitude:	In feet.
  Timezone:	Hours offset from UTC. Fractional hours are expressed as decimals, eg. India is 5.5.
  DST:	Daylight savings time. One of E (Europe), A (US/Canada), S (South America),
    O (Australia), Z (New Zealand), N (None) or U (Unknown). See also: Help: Time
  Tz: database time zone	Timezone in "tz" (Olson) format, eg. "America/Los_Angeles".
  Type:	Type of the airport. Value "airport" for air terminals, "station" for train stations,
    "port" for ferry terminals and "unknown" if not known. In airports.csv, only type=airport is included.
  Source: Source of this data. "OurAirports" for data sourced from OurAirports,
    "Legacy" for old data not matched to OurAirports (mostly DAFIF), "User" for unverified user contributions.
    In airports.csv, only source=OurAirports is included.
  
Example:
  1,"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA",-6.081689834590001,145.391998291,5282,10,
    "U","Pacific/Port_Moresby","airport","OurAirports"
  
For the routes data, each entry contains the following information:

  Airline:	2-letter (IATA) or 3-letter (ICAO) code of the airline.
  Airline ID:	Unique OpenFlights identifier for airline (see Airline).
  Source airport:	3-letter (IATA) or 4-letter (ICAO) code of the source airport.
  Source: airport ID	Unique OpenFlights identifier for source airport (see Airport)
  Destination: airport	3-letter (IATA) or 4-letter (ICAO) code of the destination airport.
  Destination: airport ID	Unique OpenFlights identifier for destination airport (see Airport)
  Codeshare:	"Y" if this flight is a codeshare (that is, not operated by Airline, but another carrier), empty otherwise.
  Stops:	Number of stops on this flight ("0" for direct)
  Equipment:	3-letter codes for plane type(s) generally used on this flight, separated by spaces
  
Example:
  2B,410,AER,2965,KZN,2990,,0,CR2
  

The three algorithms are DFS&BFS traversal, shortest path, and visualization.
To run the program, please run
  make
  ./graph
Specific instructions will be printed out after these operations.

We've also provided test cases for traversals and shorted path algorithms and the picture of testing graphs stored in /tests. To test these, please run
  make test
  ./test
</pre>
