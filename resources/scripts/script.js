const form = document.getElementById('jsonForm');

form.addEventListener('submit', async function (event) {
  event.preventDefault();

  const formData = new FormData(form);
  const formObject = Object.fromEntries(formData.entries());
  const jsonString = JSON.stringify(formObject);

  try {
    const response = await fetch('/submission', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        'Accept': 'application/json'
      },
      body: jsonString
    });

    if (response.ok) {
      const result = await response.json();
      console.log('Success:', result);
      alert('Hello: ' + result.message);
    } else {
      console.error('Server error:', response.statusText);
      alert('Submission failed.');
    }
  } catch (error) {
    console.error('Network error:', error);
    alert('An error occurred while sending data.');
  }
});
