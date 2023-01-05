package com.example.myapplication;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.ContextMenu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    EditText num1, num2, output;
    Button addBtn, subBtn, mulBtn, divBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
//        int num1 = 0, num2 = 0;
        addBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                output.setText(Integer.toString(Integer.parseInt(num1.getText().toString()) + Integer.parseInt(num2.getText().toString())));
            }
        });
        subBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                output.setText(Integer.toString(Integer.parseInt(num1.getText().toString()) - Integer.parseInt(num2.getText().toString())));
            }
        });
        mulBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                output.setText(Integer.toString(Integer.parseInt(num1.getText().toString()) * Integer.parseInt(num2.getText().toString())));
            }
        });
        divBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                output.setText(Integer.toString(Integer.parseInt(num1.getText().toString()) / Integer.parseInt(num2.getText().toString())));
            }
        });
        registerForContextMenu(addBtn);
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);
        menu.setHeaderTitle("Context Menu");
        menu.add(0, v.getId(), 0, "Yellow");
        menu.add(0, v.getId(), 0, "Gray");
        menu.add(0, v.getId(), 0, "Cyan");
    }

    @Override
    public boolean onContextItemSelected(@NonNull MenuItem item) {
        num1.setText(item.getTitle().toString());
        return true;
    }

    private void initView() {
        num1 = findViewById(R.id.inp1);
        num2 = findViewById(R.id.inp2);
        output = findViewById(R.id.result);
        addBtn = findViewById(R.id.addBtn);
        subBtn = findViewById(R.id.subBtn);
        mulBtn = findViewById(R.id.mulBtn);
        divBtn = findViewById(R.id.divBtn);
    }
}
