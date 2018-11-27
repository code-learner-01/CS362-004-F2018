// CS 362 Final Project Part B
// Daniel Bauman, Anthony Scimone, Joshua Bell

import java.util.Random;
import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

// URL Components:
// scheme:[//authority]path[?query][#fragment]



public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
  public void testManualTest()
  {
	   //You can use this function to implement your manual testing	
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   // Valid URLs
	   assertTrue(urlVal.isValid("http://www.google.com"));
	   assertTrue(urlVal.isValid("http://www.amazon.com"));
	   
	   // Invalid URLs
	   assertFalse(urlVal.isValid("http//www.google.com"));
	   assertFalse(urlVal.isValid("http://256.256.256.256"));
	   assertFalse(urlVal.isValid("http://1.2.3.4.5"));
	   assertFalse(urlVal.isValid("http://aaa."));
	   assertFalse(urlVal.isValid("http://"));
  }
   
  public void testSchemes(){
	   //You can use this function to implement your Second Partition testing
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assertTrue(urlVal.isValid("http://www.google.com"));
		assertTrue(urlVal.isValid("http://go.com"));
		assertTrue(urlVal.isValid("http://255.255.255.255"));
		assertTrue(urlVal.isValid("https://www.google.com"));
		assertTrue(urlVal.isValid("https://go.com"));
		assertTrue(urlVal.isValid("https://255.255.255.255"));
		assertTrue(urlVal.isValid("ftp://go.com"));
		assertTrue(urlVal.isValid("ftp://www.google.com"));
		assertTrue(urlVal.isValid("ftp://255.255.255.255"));
		assertTrue(urlVal.isValid("h3t://255.255.255.255"));
		assertTrue(urlVal.isValid("h3t://go.com"));
		assertTrue(urlVal.isValid("h3t://www.google.com"));
		assertTrue(urlVal.isValid("http://wwww"));
		assertTrue(urlVal.isValid("255.com"));
		assertTrue(urlVal.isValid("www.google.com"));
		
		assertFalse(urlVal.isValid("http://wwww..com"));
		assertFalse(urlVal.isValid("ftp://"));
		assertFalse(urlVal.isValid("htp://www.google.com"));
		assertFalse(urlVal.isValid("http:/www.google.com"));
		assertFalse(urlVal.isValid("fftp://www.google.com"));
		assertFalse(urlVal.isValid("//www.google.com"));
		assertFalse(urlVal.isValid("/www.google.com"));
		assertFalse(urlVal.isValid("://255.255.255.255"));
		assertFalse(urlVal.isValid("3ht://go.com"));

  }
   
  public void testAuthorities()
  {
	 //You can use this function to implement your First Partition testing
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	 	// Valid authorities  
		assertTrue(urlVal.isValid("http://www.google.com"));
		assertTrue(urlVal.isValid("http://google.cm"));
		assertTrue(urlVal.isValid("http://amazon.co"));
		assertTrue(urlVal.isValid("http://1.2.3.4"));
		
	   
	   // Invalid authorities
		assertFalse(urlVal.isValid(""));
		assertFalse(urlVal.isValid("."));
		assertFalse(urlVal.isValid(".abc"));
		assertFalse(urlVal.isValid("1.2.3.4."));
		assertFalse(urlVal.isValid("ww.go"));
		assertFalse(urlVal.isValid("8@.*!/"));

  }
 
  public void testPaths()
  {
	 //You can use this function to implement your First Partition testing
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	  	assertTrue(urlVal.isValid("http://www.google.com/file"));
	  	assertTrue(urlVal.isValid("http://www.google.com/"));
	  	assertTrue(urlVal.isValid("http://www.google.com/file1"));
	  	assertTrue(urlVal.isValid("http://www.google.com/file/file1"));
	  	assertTrue(urlVal.isValid("http://www.google.com/1234"));
	  	assertTrue(urlVal.isValid("http://www.google.com/1/file2"));
	  	assertTrue(urlVal.isValid("http://www.google.com/!#$"));
	  	assertTrue(urlVal.isValid("http://www.google.com/file/"));
	  	assertTrue(urlVal.isValid("http://www.google.com/#"));
	  	assertFalse(urlVal.isValid("http://www.google.com/../"));
	  	assertFalse(urlVal.isValid("http://www.google.com///"));
  }
   
  public void testPorts()
  {
	 //You can use this function to implement your First Partition testing
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	 	assertTrue(urlVal.isValid("http://www.google.com:80"));
	 	assertTrue(urlVal.isValid("http://www.google.com:12345"));
	 	assertFalse(urlVal.isValid("http://www.google.com:-42"));
	 	assertFalse(urlVal.isValid("http://www.google.com:80.3"));
	 	assertFalse(urlVal.isValid("http://www.google.com:3*2"));
	 	assertFalse(urlVal.isValid("http://www.google.com:"));
	 	assertFalse(urlVal.isValid("http://www.google.com:abc"));
	 	assertFalse(urlVal.isValid("http://www.google.com:abc123"));
	 	assertFalse(urlVal.isValid("http://www.google.com:123abc"));
	 	assertFalse(urlVal.isValid("http://www.google.com:h€!!0"));
	
  }
   
  public void testPortsAndPaths()
  {
	 //You can use this function to implement your First Partition testing
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	
	 	assertTrue(urlVal.isValid("http://www.google.com:80/file1"));
	 	assertTrue(urlVal.isValid("http://www.google.com:80/file1/file2"));
	 	assertTrue(urlVal.isValid("http://www.google.com:54321/file1/file2"));
	 	assertTrue(urlVal.isValid("http://www.google.com:0/file"));
	 	assertFalse(urlVal.isValid("http://www.google.com:$#!/file"));
	 	assertFalse(urlVal.isValid("http://www.google.com:80/ _22hi#@"));
	 	assertFalse(urlVal.isValid("http://www.google.com:300//file"));
	 	assertFalse(urlVal.isValid("http://www.google.com:80/.../"));
	 	assertFalse(urlVal.isValid("http://www.google.com:/file"));
  }
   

   //You need to create more test cases for your Partitions if you need to 
   
   // Programming-Based Testing
   public void part3Function()
   {
	   //You can use this function for programming based testing
	   
	   // Declare arrays of strings containing our good and bad values
	   String[] validScheme = {"http://", "ftp://", "h3t://", ""};
	   String[] invalidScheme = {"3ht://", "http:/", "http:", "http/", "://"};

	   String[] validAuthority = {"www.google.com", "go.com", "go.au", "0.0.0.0", "255.255.255.255", "255.com"};
	   String[] invalidAuthority = {"1.2.3.4.", "1.2.3", ".1.2.3.4", "go.a", "go.a1a", "go.1aa", "aaa.", ".aaa", "aaa", ""};

	   String[] validPort = {":80", ":65535", ":0",""};
	   String[] invalidPort = {"10:", "100:", "#port"};

	   String[] validPath = {"/test1", "/t123", "/$23","/test1/", "/test1/file",  ""};
	   String[] invalidPath = {"//test1", "/...", "/?23","/#test1/", "/test1///file"};


	   String[] validPathOptions = {"/test1", "/t123", "/$23", "/../", "/test1/", "/#", "", "/test1/file", "/t123/file", "/$23/file", "/../file", "/..//file", "/test1//file", "/#/file"};
	   String[] invalidPathOptions = {"test/", "$%@", "/..", "/../", "/#/test"};

	   String[] validQuery = {"?action=view", "?action=edit&mode=up", ""};
	   String[] invalidQuery = {".action=view", "%$!/query", "../,", "?query+view"};
	   
	   

		// Make a for loop that tests URLs made with random “good” values
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		Random rand = null;
		int h;
		for (h=0; h<100; h++) {
		StringBuilder trueString = new StringBuilder();
		int i = rand.nextInt((validScheme.length) + 1);
		int j = rand.nextInt((validAuthority.length) + 1);
		int m = rand.nextInt((validPathOptions.length) + 1);

		trueString.append(validScheme[i]);
		trueString.append(validAuthority[j]);
		trueString.append(validPathOptions [m]);
		
		assertTrue(urlVal.isValid(trueString.toString()));
		
		
		// Run the generated URLs
		int count = 0;
		for (h=0; h<100; h++) {
			StringBuilder falseString = new StringBuilder();

		if (count == 0) {
			i = rand.nextInt((validScheme.length) + 1);
			j = rand.nextInt((invalidAuthority.length) + 1);
			m = rand.nextInt((invalidPathOptions.length) + 1);
			
			falseString.append(validScheme[i]);
			falseString.append(invalidAuthority[j]);
			falseString.append(invalidPathOptions [m]);
			assertFalse(urlVal.isValid(falseString.toString()));
			count++;

		} else if (count == 1) {
			i = rand.nextInt((invalidScheme.length) + 1);
			j = rand.nextInt((validAuthority.length) + 1);
			m = rand.nextInt((invalidPathOptions.length) + 1);
			
			falseString.append(invalidScheme[i]);
			falseString.append(validAuthority[j]);
			falseString.append(invalidPathOptions [m]);
			assertFalse(urlVal.isValid(falseString.toString()));
			count++;
		} else { 
			i = rand.nextInt((invalidScheme.length) + 1);
			j = rand.nextInt((validAuthority.length) + 1);
			m = rand.nextInt((invalidPathOptions.length) + 1);
			
			falseString.append(invalidScheme[i]);
			falseString.append(validAuthority[j]);
			falseString.append(invalidPathOptions [m]);
			assertFalse(urlVal.isValid(falseString.toString()));
			count = 0;
		}

		
	}


	   

   }
   }
}