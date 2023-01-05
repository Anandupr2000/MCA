package com.example.navigationdrawer;

import androidx.annotation.NonNull;
import androidx.appcompat.app.ActionBarDrawerToggle;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.view.GravityCompat;
import androidx.drawerlayout.widget.DrawerLayout;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

import com.google.android.material.navigation.NavigationView;

public class MainActivity extends AppCompatActivity {
    private NavigationView nav;
    private DrawerLayout drawerLayout;
    private ActionBarDrawerToggle toggle;
    Toolbar toolbar;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        initView();


//        setting side navigation panel
        toolbar = (Toolbar) findViewById(R.id.toolbar);
//      set windowActionBar to false in theme by :
//      change <style name="Theme.NavigationDrawer" parent="whatever"> to  <style name="Theme.NavigationDrawer" parent="whatever.NoActionBar">
        setSupportActionBar(toolbar);

        toggle = new ActionBarDrawerToggle(this, drawerLayout, toolbar, R.string.nav_open, R.string.nav_close);
        drawerLayout.addDrawerListener(toggle);
        toggle.syncState();

//        toggle.onOptionsItemSelected()
        nav.setNavigationItemSelectedListener(new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                Toast.makeText(MainActivity.this, item.getTitle()+" clicked", Toast.LENGTH_LONG).show();
                drawerLayout.closeDrawer(GravityCompat.START);//reseting drawer to begining
                return false;
            }
        });
    }

    public void initView() {
        nav = (NavigationView) findViewById(R.id.navmenu);
        drawerLayout = (DrawerLayout) findViewById(R.id.drawer);
    }
}