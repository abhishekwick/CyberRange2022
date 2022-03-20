void routesConfiguration() {

  // Example of a 'standard' route
  server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  // Duplicated serving of index.html route, so the IP can be entered directly to browser.
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("route: /");
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/longBlackLarge", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("route: /longBlackLarge");
    request->send(SPIFFS, "/dashboard.html", "text/html");
  });

  server.on("/longBlackMedium", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("route: /longBlackMedium");
    request->send(SPIFFS, "/dashboard.html", "text/html");
  });

  server.on("/longBlackSmall", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("route: /longBlackSmall");
    request->send(SPIFFS, "/dashboard.html", "text/html");
  });

    server.on("/mochaLarge", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("route: /mochaLarge");
    request->send(SPIFFS, "/dashboard.html", "text/html");
  });

  server.on("/mochaMedium", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("route: /mochaMedium");
    request->send(SPIFFS, "/dashboard.html", "text/html");
  });

  server.on("/mochaSmall", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("route: /mochaSmall");
    request->send(SPIFFS, "/dashboard.html", "text/html");
  });

  // Example of linking to an external file
  server.on("/arduino.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/arduino.css", "text/css");
  });


  // Example of a route with additional authentication (popup in browser)
  // And uses the processor function.
  server.on("/dashboard.html", HTTP_GET, [](AsyncWebServerRequest * request) {
    if (!request->authenticate(http_username, http_password))
      return request->requestAuthentication();
    request->send(SPIFFS, "/dashboard.html", "text/html", false, processor);
  });

  // Example of route with authentication, and use of processor
  // Also demonstrates how to have arduino functionality included (turn LED on)
  server.on("/LEDOn", HTTP_GET, [](AsyncWebServerRequest * request) {
    if (!request->authenticate(http_username, http_password))
      return request->requestAuthentication();
    digitalWrite(LED_BUILTIN, HIGH);
    request->send(SPIFFS, "/dashboard.html", "text/html", false, processor);
  });

  // Example of route which sets file to download - 'true' in send() command.
  server.on("/logOutput", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("output");
    request->send(SPIFFS, "/logEvents.csv", "text/html", true);
  });
}

String processor(const String& var) {
  /*
     Updates the HTML by replacing set variables with return value from here.
     For example:
     in HTML file include %VARIABLEVALUE%.
     In this function, have:
      if (var=="VARIABLEVALUE") { return "5";}
  */


  // Default "catch" which will return nothing in case the HTML has no variable to replace.
  return String();
}
