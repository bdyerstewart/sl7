Houston AI


This module allows Drupal websites to connect with the Houston.ai service.  At this time, the module supports only
the classifier API.

Usage
  To use the API, you must acquire a license key from Houston.ai
  Enter the key in the Houston AI configuration page.  You can also set a default location to use as a default if the
  user does not enter one.

  Classifier API:
  https://houston.ai/api/classify-docs

  To use, see our api.php document.

  The hook_houston_ai_classify accepts three arguments:
  *location: a string of the user's location
  *problem: a string of the user's problem
  *document: a base64 string from a document (see the classifier demo)
  If the document is empty, the problem will be used.  Otherwise, the document will be used.  This will return an object.

  Data structure includes:
  * code (code and label)
  * geo (location data)
  * message
  * other probabilities (any other matches below the best one)
  * probability (% confidence of the top result)
  * proper nouns (if detected)
  * sessionid

  The hook_houston_ai_classify_feedback accepts four arguments:
  * sessionid -- the session ID from the classify object
  * wasCorrect -- a boolean of whether the returned code was correct or not
  * actualCode -- the code of the correct code
  * comment --- any comment the user may have left


Sample Usage
  * Call houston_ai_classify($location, $problem, $document) in your custom module and process the results.
  * If you want to provide feedback (please!), call houston_ai_classify_feedback in your custom code.





