javascript:(async function() {
    let titleElement =
        document.querySelector('span.text-title-large') ||
        document.querySelector('[data-cy="question-title"]');

    let defaultTitle = "";

    if (titleElement && titleElement.innerText) {
        defaultTitle = titleElement.innerText
            .replace(/^[0-9]+\.\s*/, '')
            .trim()
            .replace(/\s+/g, '-');
    } else {
        const pathSegments = window.location.pathname.split('/');
        const problemsIndex = pathSegments.indexOf('problems');

        if (problemsIndex !== -1 && pathSegments[problemsIndex + 1]) {
            const slug = pathSegments[problemsIndex + 1];

            defaultTitle = slug
                .split('-')
                .map(
                    word =>
                        word.charAt(0).toUpperCase() + word.slice(1)
                )
                .join('-');
        } else {
            defaultTitle = "leetcode-problem";
        }
    }

    let suggestedName = `${defaultTitle}.cpp`;
    let customTitle = prompt(
        "Confirm or modify the filename and extension:",
        suggestedName
    );

    if (customTitle === null) return;

    const finalTitle =
        customTitle.trim() === ""
            ? suggestedName
            : customTitle.replace(/\s+/g, %27-%27);

    let code = "";

    if (window.monaco && window.monaco.editor) {
        const editors = window.monaco.editor.getModels();

        if (editors.length > 0) {
            code = editors[0].getValue();
        }
    }

    if (!code) {
        const codeLines = document.querySelectorAll(%27.view-line%27);

        if (codeLines.length > 0) {
            code = Array.from(codeLines)
                .map(line => line.textContent)
                .join(%27\n%27);
        }
    }

    if (!code) {
        alert(
            "[ERROR] Failed to capture code. Please click inside the editor and try again."
        );
        return;
    }

    try {
        const response = await fetch("http://localhost:3000/salvar", {
            method: %27POST%27,
            headers: {
                %27Content-Type%27: %27application/json%27
            },
            body: JSON.stringify({
                title: finalTitle,
                code
            })
        });

        if (response.ok) {
            alert("[SUCCESS] Code successfully pushed to GitHub.");
        } else {
            alert("[ERROR] Server failed to process the request.");
        }
    } catch (err) {
        alert(
            "[ERROR] Local server connection failed. Is %27node server.js%27 running?"
        );
    }
})();
