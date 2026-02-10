import os
from PyPDF2 import PdfReader, PdfWriter

def remove_pdf_passwords(pdf_password: str):
    # Get directory of current file
    base_dir = os.path.dirname(os.path.abspath(__file__))

    input_dir = os.path.join(base_dir, "docs")
    output_dir = os.path.join(base_dir, "docs2")

    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)

    for filename in os.listdir(input_dir):
        if not filename.lower().endswith(".pdf"):
            continue

        input_path = os.path.join(input_dir, filename)
        output_path = os.path.join(output_dir, filename)

        reader = PdfReader(input_path)

        # Decrypt PDF
        if reader.is_encrypted:
            if not reader.decrypt(pdf_password):
                print(f"❌ Wrong password for: {filename}")
                continue

        writer = PdfWriter()

        for page in reader.pages:
            writer.add_page(page)

        # Write unprotected PDF
        with open(output_path, "wb") as f:
            writer.write(f)

        print(f"✅ Unlocked and saved: {filename}")

if __name__ == "__main__":
    PASSWORD = "JAEPK6068P3137"
    remove_pdf_passwords(PASSWORD)
