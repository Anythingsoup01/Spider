const form = document.getElementById('jsonForm');

form.addEventListener('submit', async function (event) {
  // 1. Prevent the default browser form submission (prevents page reload)
  event.preventDefault();

  // 2. Automatically gather all form field data
  const formData = new FormData(form);

  // 3. Convert the FormData object into a standard JavaScript object
  const formObject = Object.fromEntries(formData.entries());

  // 4. Convert the JavaScript object into a JSON string
  const jsonString = JSON.stringify(formObject);

  try {
    // 5. Send the JSON string via a POST request
    const response = await fetch('/submission', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json', // Tells the server to expect JSON
        'Accept': 'application/json'
      },
      body: jsonString
    });

    if (response.ok) {
      const result = await response.json();
      console.log('Success:', result);
      alert('Form submitted successfully!');
    } else {
      console.error('Server error:', response.statusText);
      alert('Submission failed.');
    }
  } catch (error) {
    console.error('Network error:', error);
    alert('An error occurred while sending data.');
  }
});
